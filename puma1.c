// puma1.cpp : 定义控制台应用程序的入口点。
//

#define _CRT_SECURE_NO_WARNINGS
//#include "stdafx.h"
#include "http11_parser.h"
#include "http_parser.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void http_field_cb(struct puma_parser* hp,
    const char *field, size_t flen,
    const char *value, size_t vlen)
{
}

void common_element_cb(struct puma_parser* hp,
    const char *at, size_t length)
{
}

//s = "GET /abc HTTP/1.1\r\n";
const char *packet = "GET /favicon.ico HTTP/1.1\r\n"
            "Host: 0.0.0.0=5000\r\n"
            "User-Agent: Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9) Gecko/2008061015 Firefox/3.0\r\n"
            "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
            "Accept-Language: en-us,en;q=0.5\r\n"
            "Accept-Encoding: gzip,deflate\r\n"
            "Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7\r\n"
            "Keep-Alive: 300\r\n"
            "Connection: keep-alive\r\n"
            "\r\n";

void puma(int n)
{
    puma_parser parser;
    parser.http_field = http_field_cb;
    parser.request_method = common_element_cb;
    parser.request_uri = common_element_cb;
    parser.fragment = common_element_cb;
    parser.request_path = common_element_cb;
    parser.query_string = common_element_cb;
    parser.http_version = common_element_cb;
    parser.header_done = common_element_cb;
    size_t rc;
int i;
    for (i=0;i!=n;++i) {
        char s[1024];
        strcpy(s, packet);
        size_t l = strlen(s);
        puma_parser_init(&parser);
        rc = puma_parser_execute(&parser, s, l, 0);
        assert(rc == l);
    }
}

int my_http_data_cb (http_parser* p, const char *at, size_t length)
{
    return 0;
}
int my_http_cb (http_parser* p)
{
    return 0;
}

void nginx(int n)
{
    http_parser parser;
    http_parser_settings setting;
    setting.on_message_begin = my_http_cb;
    setting.on_headers_complete = my_http_cb;
    setting.on_message_complete = my_http_cb;
    setting.on_chunk_header = my_http_cb;
    setting.on_chunk_complete = my_http_cb;

    setting.on_url = my_http_data_cb;
    setting.on_status = my_http_data_cb;
    setting.on_header_field = my_http_data_cb;
    setting.on_header_value = my_http_data_cb;
    setting.on_body = my_http_data_cb;

    size_t rc;
int i;
    for (i = 0; i != n; ++i) {
        char s[1024];
        strcpy(s, packet);
        size_t l = strlen(s);
        http_parser_init(&parser, HTTP_REQUEST);
        rc = http_parser_execute(&parser, &setting, s, l);
        assert(rc == l);
    }
}

int main(int argc, char* argv[])
{
    if (argc < 3){
        printf("test 3 nginx\n");
        return -1;
    }

    int n = atoi(argv[1]);
    if (!strcmp(argv[2], "nginx")) {
        printf("text nginx %d\n", n);
        nginx(n);
    }
    else{
        printf("text puma %d\n", n);
        puma(n);
    }
    return 0;
}

