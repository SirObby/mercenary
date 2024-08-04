#pragma once

#include <json.h>
#include <stdio.h>
#include <stdbool.h>

// AP extensions.
typedef struct apub_extensions {
    bool manuallyApprovesFollowers; // as:manuallyApprovesFollowers
    bool discoverable; // toot:discoverable
    bool indexable; // toot:indexable
} apub_extensions;

// Pub actor.
typedef struct apub
{
    char* name;
    char* summary;
    char* preferredUsername;
    char* id; // id will just be (instancename)/@username, basically the url.
    char* url; // for mercenary this will be same as id;
    char* type; // 100% It's just gonna be "Person", but bots and such might have other types.
    struct json_object *object; // Initial object to create this 'apub' struct.
    char* inbox; // link
    char* outbox; // link
    char* published; // date published.
    //char* icon; // icon. to be implemented.
    //char* image; // image. to be implemented.
    apub_extensions extensions;
} apub;

apub from_json(char *str);
char* to_json(apub *ap); // Also modified json_object type object to be accurate.

