# Database

mercenary uses its own database system and custom format, this is to ensure that the mercenary project is as reliable as possible, by keeping every system in the same place. (no external db like postgres)

## Design / Progress
The idea for the mercenary database, is that all data is stored sequentially.
The manifest file will the database header and information of included data.
The database reader will find the file from the request hash (for example account id hash's first 2 characters) and read it sequentially.
Each entry of data can be 1 of 4 types.
- Single type (This is an entry that has a name and a value) (takes in name, value)
- Array type (This is an entry that declares that there is an array of values with this name.) (takes in name)
- Array entry type (This is an entry of an array with name) (takes in name, value)
- Schema type (This entry allows for a complex data.) (schema)

## Progress
- [ ] Manifest
- [ ] Database Format
- [ ] Schema
- [ ] Reader
- [ ] Writer