#pragma once

#include <json-c/json.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum ActivityType{
    // Core types.
    Object,
    Link,
    Activity,
    IntransitiveActivity,
    Collection,
    OrderedCollection,
    CollectionPage,
    OrderedCollectionPage,
    // Social types.
    Accept,
    Add,
    Announce,
    Arrive, // Can be used to "boost" a post with just post-url as object.
    Block,
    Create, 
    Delete,
    Dislike,
    Flag,
    Follow,
    Ignore,
    Invite,
    Join,
    Leave,
    Like,
    Listen,
    Move,
    Offer,
    Question,
    Reject,
    Read,
    Remove,
    TentativeReject,
    TentativeAccept,
    Travel,
    Undo,
    Update,
    View
} ActivityType;

typedef enum ActivityObjectType {
    Article,
    Audio,
    Document,
    Event,
    Image,
    Note, // Will be implemented.
    Page,
    Place,
    Profile,
    Relationship,
    Tombstone,
    Video
} ActivityObjectType;

typedef struct ActivityObject {
    // There may be situations where the JSON representation of the "object" field cannot be
    // fully represented within mercenary, which is why we also include the full json object here.
    struct json_object *json;

    char* string;
    ActivityType type;

    // Note.
    char* name;
    char* content;
} ActivityObject;

typedef struct ActivityStream {
    // There may be situations where the JSON representation of an ActivityStream cannot be fully
    // represented within mercenary, which is why we also include the full json object here.
    struct json_object *json;
    ActivityType type;
    char** context; // https://www.w3.org/ns/activitystreams
    
    char** to; // https://www.w3.org/ns/activitystreams#Public
    char** cc; // i.e. Followers
    
    char* summary;

    ActivityObject obj; // i.e. Type "Note"
} ActivityStream;

// AP extensions.
typedef struct apub_extensions {
    bool manuallyApprovesFollowers; // as:manuallyApprovesFollowers
    bool discoverable; // toot:discoverable
    bool indexable; // toot:indexable
} apub_extensions;


// Pub actor.
typedef struct apub
{
    struct json_object *json; // The JSON representation of this Actor object.
    // There may be instances where the fields implemented in mercenary do not reflect all the JSON-LD in the 
    // Provided Actor object.
    char* name;
    char* summary;
    char* preferredUsername;
    char* id; // id will just be (instancename)/@username, basically the url.
    char* url; // for mercenary this will be same as id;
    char* type; // 100% It's just gonna be "Person", but bots and such might have other types.
     char* inbox; // link
     char* outbox; // link
     char* followers; // link
     char* following; // link
    // char* liked; // link
    char* published; // date published.
    //char* icon; // icon. to be implemented.
    //char* image; // image. to be implemented.
    apub_extensions extensions;

    ActivityStream **in;
    ActivityStream **out;
    char **followers_; // Links of urls;
    char **following_; // Links fo urls
    //ActivityStream **liked;
} apub;

