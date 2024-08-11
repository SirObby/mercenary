#include "mongoose.h"   
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "database/con.h"

#include <pub.h>

// HTTP server event handler function
void ev_handler(struct mg_connection *c, int ev, void *ev_data) {
  if (ev == MG_EV_HTTP_MSG) {
    struct mg_http_message *hm = (struct mg_http_message *) ev_data;
    if (mg_match(hm->uri, mg_str("/@*"), NULL)) { 
      mg_http_reply(c, 200, "", "{\"result\": \"%.*s\"}\n", (int) hm->uri.len,
                    hm->uri.buf);
    } else if (mg_match(hm->uri, mg_str("/json/*"), NULL)) { 
      mg_http_reply(c, 200, "", "{\"result\": \"%.*s\"}\n", (int) hm->uri.len,
                    hm->uri.buf);
    } else {
    struct mg_http_serve_opts opts = { .root_dir = "./public/" };
    mg_http_serve_dir(c, hm, &opts);
    }
  }
}

int main(int argc, char** argv) {

  struct mg_mgr mgr;  // Declare event manager
  mg_mgr_init(&mgr);  // Initialise event manager
  mg_http_listen(&mgr, "http://0.0.0.0:3000", ev_handler, NULL);  // Setup listener
  for (;;) {          // Run an infinite event loop
    mg_mgr_poll(&mgr, 1000);
  }
  
  return 0;
}