# ftpd

FTP Server for AmigaOS4 based on https://github.com/mtheall/ftpd.

## Features

- Appears to work well with a variety of clients.
- Supports multiple simultaneous clients.
- Cutting-edge graphics.

## Latest Builds

https://www.amigasoft.net/simple-ftp-server/

## Build and install

You need the latest <a href="https://github.com/afxgroup/clib2">clib2</a> to compile it.

Just do:  
    make 3dsx

## Supported Commands

- ABOR
- ALLO (no-op)
- APPE
- CDUP
- CWD
- DELE
- FEAT
- HELP
- LIST
- MDTM
- MKD
- MLSD
- MLST
- MODE (no-op)
- NLST
- NOOP
- OPTS
- PASS (no-op)
- PASV
- PORT
- PWD
- QUIT
- REST
- RETR
- RMD
- RNFR
- RNTO
- SIZE
- STAT
- STOR
- STRU (no-op)
- SYST
- TYPE (no-op)
- USER (no-op)
- XCUP
- XCWD
- XMKD
- XPWD
- XRMD

## Planned Commands

- STOU
