# mercenary
An optimization and performance focused ActivityPub server, using [mongoose](https://github.com/cesanta/mongoose) (found in mongoose.c and mongoose.h)

## Progress
- [x] HTTP backend server (mongoose.c, my beloved)
- [ ] Database (For now we will simply be using postgresql.)
- [ ] Configuration system
- [ ] ActivityPub
- [ ] Oauth2

## ActivityPub Implemented fields:
- [ ] Actor
- [ ] Inbox
- [ ] Outbox
- [ ] Followers Collection
- [ ] Following Collection
- [ ] Liked Collection
- [ ] Public Addressing
- [ ] Likes Collection
- [ ] Shares Collection
- [ ] Activities (i.e. Notes)

## Why NixOS sucks for development using PostgreSQL on C.

[libpq isn't a fucking package.](https://github.com/NixOS/nixpkgs/issues/61580).