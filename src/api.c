#include <api.h>

void receive_api_call(struct mg_http_message *hm, struct mg_connection *c) {
    
    bool is_logged_in = false;

    char user[256], pass[256];
    mg_http_creds(hm, user, sizeof(user), pass, sizeof(pass));
    if(pass != NULL) is_logged_in = true;



    // Check if user is authenthicated.
    if(is_logged_in == false) {
        mg_http_reply(c, 403, "", "Denied\n");
    }



};