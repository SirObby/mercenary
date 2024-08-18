#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <libpq-fe.h>

#include <json.h>

typedef struct database_user
{
    uint64_t identity; 

    struct json_object *json;

    char** username;
    char** hash_password;
    char** email;

    uint64_t unit_createdtime;
} database_user;

typedef struct bearer_token {
    uint64_t identity;
    char token[256];
} bearer_token;

