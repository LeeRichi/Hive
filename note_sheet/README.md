
# Notes and Sheet

This folder is for personal/customize systems settings like shell, OS shortcut or even notes for my daily development.

## shortcuts
### linux
- screen shot
- editor line jumping

### mac
- no different color terminal feature 😔
- no feature for open new terminal window but same location

## Commands
### psql
to enter
```bash
psql -U postgres
```
list databases
```bash
\l
```
list roles
```bash
\du
```

### docker
enter shell
```bash
docker-compose run app sh
```
run shell
```bash
docker-compose up --build
docker-compose up -d       //this one runs in background
```

### aws
connent to aws instance
```bash
ssh -i ${key_file} ${server_name}@${public_address}
```
Server_name is ubuntu in my case.
