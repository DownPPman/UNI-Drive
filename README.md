 host$ mkdir ~/yocto
 Get the manifest that describes the location of the BSP sources:
 host$ mkdir ~/tauris
 host$ cd ~/tauris
 host$ git clone ssh://git@git.phytec.de/meta-pbacd20
 host$ cd meta-pbacd20
 host$ git checkout -b manifest remotes/origin/manifest
 host$ cp <manifest.xml> ~/yocto
 © PHYTEC Messtecknik GmbH
 27
Hardware and BSP Manual - phyGATE-Tauri-S i.MX 6UL/ULL Kit (L-1012e.A3)
 Download and run the phyLinux script:
 host$ cd ~/yocto
 host$ wget https://download.phytec.de/Software/Linux/Yocto/Tools/phyLinux
 host$ chmod +x phyLinux
 host$ ./phyLinux init -x <manifest.xml>
 6.2 Basic Set-Up
 There are a few important steps that have to be done before the main build process can start.
 •
 •
 To set up the host, see Setting up the Host. 
To set the Git configuration, see Git Configuration

 ./phyLinux init -x BSP-Yocto-phyGATE-Tauri-S-ALPHA1.xml
repo tool wrapper is installed: /usr/local/bin/repo
no repo repository in current directory
installing repo tool
default: using stable branch of phytec repo-tool
no repository initialized
Initializing from an empty directory
using a local manifest XML: BSP-Yocto-phyGATE-Tauri-S-ALPHA1.xml
$ git init .localxml
Initialized empty Git repository in /home/phyvm/yocto/.localxml/.git/

$ cd .localxml;git add default.xml;git add localxml.xml;git commit -m init;git checkout -b localxml;cd ..;
[master (root-commit) b500608] init
 2 files changed, 80 insertions(+)
 create mode 100644 default.xml
 create mode 100644 localxml.xml
Switched to a new branch 'localxml'

updating remote phytec repo repository
$ repo init --repo-url=https://git.phytec.de/git/git-repo --repo-branch=stable -u /home/phyvm/yocto/.localxml
Downloading Repo source from https://git.phytec.de/git/git-repo
remote: Objekte aufzählen: 8146, fertig.
remote: Zähle Objekte: 100% (8146/8146), fertig.
remote: Komprimiere Objekte: 100% (3380/3380), fertig.
remote: Gesamt 8146 (Delta 5511), Wiederverwendet 7253 (Delta 4685)
Receiving objects: 100% (8146/8146), 3.41 MiB | 2.47 MiB/s, done.
Resolving deltas: 100% (5511/5511), done.


Your identity is: mein-nutzername <meine=mail.de>
If you want to change this, please re-run 'repo init' with --config-name

repo has been initialized in /home/phyvm/yocto/
If this is not the directory in which you want to initialize repo, please run:
   rm -r /home/phyvm/yocto//.repo
and try again.

Selecting SoC to command line argument: localxml
switching to localxml
$ repo init -b localxml

Your identity is: mein-nutzername <meine=mail.de>
If you want to change this, please re-run 'repo init' with --config-name

repo has been initialized in /home/phyvm/yocto/
If this is not the directory in which you want to initialize repo, please run:
   rm -r /home/phyvm/yocto//.repo
and try again.

Selecting Release to command line argument: localxml
switching to localxml
$ repo init -m localxml.xml


Your identity is: mein-nutzername <meine=mail.de>
If you want to change this, please re-run 'repo init' with --config-name

repo has been initialized in /home/phyvm/yocto/
If this is not the directory in which you want to initialize repo, please run:
   rm -r /home/phyvm/yocto//.repo
and try again.

syncing sources
$ repo sync
Fetching:  0% (0/9) warming up
fatal: unable to connect to github.com:
github.com[0: 140.82.121.3]: errno=Connection timed out


rauc/meta-rauc:
fatal: unable to connect to github.com:
github.com[0: 140.82.121.3]: errno=Connection timed out

rauc/meta-rauc: sleeping 4.0 seconds before retrying
fatal: unable to connect to github.com:
github.com[0: 140.82.121.3]: errno=Connection timed out


rauc/meta-rauc:
fatal: unable to connect to github.com:
github.com[0: 140.82.121.3]: errno=Connection timed out
error: Cannot fetch rauc/meta-rauc from git://github.com/rauc/meta-rauc

fatal: unable to connect to github.com:
github.com[0: 140.82.121.4]: errno=Connection timed out


meta-qt5/meta-qt5:
fatal: unable to connect to github.com:
github.com[0: 140.82.121.4]: errno=Connection timed out

meta-qt5/meta-qt5: sleeping 4.0 seconds before retrying
fatal: unable to connect to github.com:
github.com[0: 140.82.121.4]: errno=Connection timed out


meta-qt5/meta-qt5:
fatal: unable to connect to github.com:
github.com[0: 140.82.121.4]: errno=Connection timed out
error: Cannot fetch meta-qt5/meta-qt5 from git://github.com/meta-qt5/meta-qt5
Fetching: 100% (9/9), done in 23m46.995s
Garbage collecting: 100% (9/9), done in 0.404s
Fetching:  0% (0/2) warming up
fatal: unable to connect to github.com:
github.com[0: 140.82.121.3]: errno=Connection timed out


meta-qt5/meta-qt5:
fatal: unable to connect to github.com:
github.com[0: 140.82.121.3]: errno=Connection timed out

meta-qt5/meta-qt5: sleeping 4.0 seconds before retrying
fatal: unable to connect to github.com:
github.com[0: 140.82.121.4]: errno=Connection timed out


meta-qt5/meta-qt5:
fatal: unable to connect to github.com:
github.com[0: 140.82.121.4]: errno=Connection timed out
error: Cannot fetch meta-qt5/meta-qt5 from git://github.com/meta-qt5/meta-qt5

fatal: unable to connect to github.com:
github.com[0: 140.82.121.4]: errno=Connection timed out


rauc/meta-rauc:
fatal: unable to connect to github.com:
github.com[0: 140.82.121.4]: errno=Connection timed out

rauc/meta-rauc: sleeping 4.0 seconds before retrying
fatal: unable to connect to github.com:
github.com[0: 140.82.121.3]: errno=Connection timed out


rauc/meta-rauc:
fatal: unable to connect to github.com:
github.com[0: 140.82.121.3]: errno=Connection timed out
error: Cannot fetch rauc/meta-rauc from git://github.com/rauc/meta-rauc
Fetching: 100% (2/2), done in 8m51.164s
Garbage collecting: 100% (2/2), done in 0.119s
error: Cannot checkout meta-qt5/meta-qt5: ManifestInvalidRevisionError: revision dunfell in meta-qt5/meta-qt5 not found
error: in `sync`: revision dunfell in meta-qt5/meta-qt5 not found

BSP has phyLinux API Version 2
REPO_MANIFEST="${ROOTDIR}/.repo/manifest.xml"
if [ -L ${REPO_MANIFEST} ]; then
	RELEASE_UID=$(sed -n 's:.*release_uid="\([^"]*\).*:\1:p' ${REPO_MANIFEST})
        INC_MANIFEST=`grep -o '".*\.xml"' ${REPO_MANIFEST} | sed 's/"//g'`
Traceback (most recent call last):
  File "/home/phyvm/yocto/sources/meta-phytec/scripts/copy_file_by_priority.py", line 77, in <module>
    main()
  File "/home/phyvm/yocto/sources/meta-phytec/scripts/copy_file_by_priority.py", line 70, in main
    bsp = BSP_BBLayerFile()
  File "/home/phyvm/yocto/sources/meta-phytec/scripts/copy_file_by_priority.py", line 26, in __init__
    priority = self.__get_priority(layer_conf)
  File "/home/phyvm/yocto/sources/meta-phytec/scripts/copy_file_by_priority.py", line 32, in __get_priority
    with open(layer_conf) as lcfile:
FileNotFoundError: [Errno 2] No such file or directory: '/home/phyvm/yocto/sources/meta-qt5/conf/layer.conf'
Traceback (most recent call last):
  File "/home/phyvm/yocto/sources/meta-phytec/scripts/copy_file_by_priority.py", line 77, in <module>
    main()
  File "/home/phyvm/yocto/sources/meta-phytec/scripts/copy_file_by_priority.py", line 70, in main
    bsp = BSP_BBLayerFile()
  File "/home/phyvm/yocto/sources/meta-phytec/scripts/copy_file_by_priority.py", line 26, in __init__
    priority = self.__get_priority(layer_conf)
  File "/home/phyvm/yocto/sources/meta-phytec/scripts/copy_file_by_priority.py", line 32, in __get_priority
    with open(layer_conf) as lcfile:
FileNotFoundError: [Errno 2] No such file or directory: '/home/phyvm/yocto/sources/meta-yogurt/conf/layer.conf'
Traceback (most recent call last):
  File "/home/phyvm/yocto/sources/meta-phytec/scripts/copy_file_by_priority.py", line 77, in <module>
    main()
  File "/home/phyvm/yocto/sources/meta-phytec/scripts/copy_file_by_priority.py", line 70, in main
    bsp = BSP_BBLayerFile()
  File "/home/phyvm/yocto/sources/meta-phytec/scripts/copy_file_by_priority.py", line 26, in __init__
    priority = self.__get_priority(layer_conf)
  File "/home/phyvm/yocto/sources/meta-phytec/scripts/copy_file_by_priority.py", line 32, in __get_priority
    with open(layer_conf) as lcfile:
FileNotFoundError: [Errno 2] No such file or directory: '/home/phyvm/yocto/sources/meta-virtualization/conf/layer.conf'
tools/init: 78: cd: can't cd to /home/phyvm/yocto/sources/poky/
tools/init: 79: .: Can't open ./oe-init-build-env
