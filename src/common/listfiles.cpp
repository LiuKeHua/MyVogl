/**************************************************************************
 *
 * Copyright 2013-2014 RAD Game Tools and Valve Software
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 **************************************************************************/

//#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <vogl_core.h>
#include <vogl_json.h>

#include <iomanip>
#include <sstream>

#include "commands.h"
#include "listfiles.h"

int
AskForTraceFileList(unsigned int *pbuffer_size, char **pbuffer)
{
    unsigned int cbBuff = sizeof(int32_t);
    char * pbBuff = (char *)malloc(cbBuff);
    if (NULL == pbBuff)
    {
        printf("OOM\n");
        return -1;
    }

    //  First part of buffer is the command id
    *((int32_t *)pbBuff) = TRACE_LIST_TRACES;

    *pbuffer = pbBuff;
    *pbuffer_size = cbBuff;

    return 0;
}

//
//  Lists the set of trace files on the server
//
int
ListTraceFiles(unsigned int *pbuffer_size, char **pbuffer)
{
    DIR           *d;
    struct dirent *dir;
    std::string strTraceLocation;
    const char *szTraceLocation = NULL;

    vogl::json_document cur_doc;
    vogl::dynamic_string dst;

    char *pbBuff;
    unsigned int cbBuff;

    // Add list of files
    vogl::json_node &meta_node2 = cur_doc.get_root()->add_array("trace_list");

    //
    //  Find the correct directory
    //
    //
    //  Handle the destination directory for the file as per spec
    //    $XDG_DATA_HOME defines the base directory relative to which user specific data files should be stored.
    //    If $XDG_DATA_HOME is either not set or empty, a default equal to $HOME/.local/share should be used.
    szTraceLocation = getenv("XDG_DATA_HOME");
    if (NULL == szTraceLocation)
    {
        strTraceLocation = getenv("HOME");
        strTraceLocation += "/.local/share";
    }
    else
    {
        strTraceLocation = szTraceLocation;
    }
    strTraceLocation += "/vogl/";

    d = opendir(strTraceLocation.c_str());
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if (DT_REG == dir->d_type)
            {
                meta_node2.add_value(dir->d_name);
            }
        }

        closedir(d);
    }

    cur_doc.serialize(dst);

    cbBuff = dst.get_len() + 1 + sizeof(int32_t);
    pbBuff = (char *)malloc(cbBuff);
    if (NULL == pbBuff)
    {
        printf("OOM\n");
        return -1;
    }

    //  First part of buffer is the command id
    *((int32_t *)pbBuff) = TRACE_LIST;
    strncpy((char *)(pbBuff+sizeof(int32_t)), dst.get_ptr(), cbBuff - sizeof(int32_t));

    *pbuffer = pbBuff;
    *pbuffer_size = cbBuff;

    return 0;
}

int DumpTraceFileList(unsigned int buffer_size, char *buffer)
{
    vogl::json_document cur_doc;

    if (0 == buffer_size)
        return -1;

    cur_doc.deserialize(buffer);

    // Read filelist in.
    const vogl::json_node *file_array = cur_doc.get_root()->find_child_array( "trace_list" );
    for (uint i = 0; i < file_array->size(); i++)
    {
        const char * str = file_array->value_as_string_ptr(i);
        printf( "%d: %s\n", i, str );
    }

    return 0;
}

