# mercenary
An optimization and performance focused ActivityPub server, using [mongoose](https://github.com/cesanta/mongoose) (found in mongoose.c and mongoose.h)

## Prerequisites:
### Debian
- libjson-c-dev
- libpq-dev
### Nix
bro just use the shell.nix

## Progress
- [x] HTTP backend server (mongoose.c, my beloved)
- [ ] Configuration system
- [ ] ActivityPub
    - [ ] Inbox/Outbox
    - [ ] Activities
    - [ ] Actors
- [ ] Database
    - [ ] PostgreSQL
    - [ ] Actor objects.
    - [ ] Activities.
    - [ ] Custom implementation
        - [ ] Storage
- [ ] Storage
- [ ] Webfinger
- [ ] Oauth2

## Why NixOS sucks for development using PostgreSQL on C.

[libpq isn't a fucking package.](https://github.com/NixOS/nixpkgs/issues/61580).

## eee
https://www.w3.org/wiki/ActivityPub/Primer
