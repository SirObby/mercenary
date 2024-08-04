#include <pub.h>

apub from_json(char *str) {
    apub ap;

    struct json_object *jobj;
    jobj = json_tokener_parse(str);

    ap.object = jobj;

    // to do.

};
char* to_json(apub *ap) {
    
};
