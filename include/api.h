#pragma once

#include <stdbool.h>
#include "mongoose.h"

#include <database/con.h>

void receive_api_call(struct mg_http_message *hm, struct mg_connection *c);