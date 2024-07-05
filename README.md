hyvm@imx6ul:~/yocto$ ./phyLinux init -x BSP-Yocto-phyGATE-Tauri-S-ALPHA1.xml
repo tool wrapper is installed: /usr/local/bin/repo
repo is installed in the current directory
default: using stable branch of phytec repo-tool

This current directory is not empty. It could lead to errors in the BSP configuration
process if you continue from here. At least you have to check your build directory
for settings in bblayers.conf and local.conf, which will not be handled correctly in.
all cases. It is advisable to start from an empty directory of call:
$ ./phyLinux clean
Do you really want to continue from here?
[yes/no]:
$ no
phyvm@imx6ul:~/yocto$ ./phyLinux clean
You current working directory is:
/home/phyvm/yocto
Do you really want to clean the following files:
['.localxml', '.repo/manifests.git']
[yes/no]:
$ 
$ rm -fr ".localxml"

$ rm -fr ".repo/manifests.git"

phyvm@imx6ul:~/yocto$ ./phyLinux clean
You current working directory is:
/home/phyvm/yocto
We dont have any files to clean in this directory.
phyvm@imx6ul:~/yocto$ ./phyLinux init -x BSP-Yocto-phyGATE-Tauri-S-ALPHA1.xml
repo tool wrapper is installed: /usr/local/bin/repo
repo is installed in the current directory
default: using stable branch of phytec repo-tool
no repository initialized
Initializing from an empty directory
using a local manifest XML: BSP-Yocto-phyGATE-Tauri-S-ALPHA1.xml
$ git init .localxml
Initialized empty Git repository in /home/phyvm/yocto/.localxml/.git/

$ cd .localxml;git add default.xml;git add localxml.xml;git commit -m init;git checkout -b localxml;cd ..;
[master (root-commit) 42fdcc9] init
 2 files changed, 80 insertions(+)
 create mode 100644 default.xml
 create mode 100644 localxml.xml
Switched to a new branch 'localxml'

updating remote phytec repo repository
$ repo init --repo-url=https://git.phytec.de/git/git-repo --repo-branch=stable -u /home/phyvm/yocto/.localxml

Testing colorized output (for 'repo diff', 'repo status'):
  black    red      green    yellow   blue     magenta   cyan     white 
  bold     dim      ul       reverse 
Enable color display in this user account (y/N)? y

repo has been initialized in /home/phyvm/yocto/
If this is not the directory in which you want to initialize repo, please run:
   rm -r /home/phyvm/yocto//.repo
and try again.

Selecting SoC to command line argument: localxml
switching to localxml
$ repo init -b localxml

repo has been initialized in /home/phyvm/yocto/
If this is not the directory in which you want to initialize repo, please run:
   rm -r /home/phyvm/yocto//.repo
and try again.

Selecting Release to command line argument: localxml
switching to localxml
$ repo init -m localxml.xml

repo has been initialized in /home/phyvm/yocto/
If this is not the directory in which you want to initialize repo, please run:
   rm -r /home/phyvm/yocto//.repo
and try again.

syncing sources
$ repo sync
Fetching:  0% (0/10) warming up

Fetching: 40% (4/10) meta-phytec
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
Fetching: 60% (6/10) poky
fatal: unable to connect to github.com:
github.com[0: 140.82.121.4]: errno=Connection timed out


rauc/meta-rauc:
fatal: unable to connect to github.com:
github.com[0: 140.82.121.4]: errno=Connection timed out

rauc/meta-rauc: sleeping 4.0 seconds before retrying
fatal: unable to connect to github.com:
github.com[0: 140.82.121.4]: errno=Connection timed out


rauc/meta-rauc:
fatal: unable to connect to github.com:
github.com[0: 140.82.121.4]: errno=Connection timed out
error: Cannot fetch rauc/meta-rauc from git://github.com/rauc/meta-rauc
Fetching: 100% (10/10), done in 9m36.995s
Garbage collecting: 100% (10/10), done in 0.603s
Fetching:  0% (0/2) warming up
fatal: unable to connect to github.com:
github.com[0: 140.82.121.3]: errno=Connection timed out


meta-qt5/meta-qt5:
fatal: unable to connect to github.com:
github.com[0: 140.82.121.3]: errno=Connection timed out

meta-qt5/meta-qt5: sleeping 4.0 seconds before retrying
fatal: unable to connect to github.com:
github.com[0: 140.82.121.3]: errno=Connection timed out


meta-qt5/meta-qt5:
fatal: unable to connect to github.com:
github.com[0: 140.82.121.3]: errno=Connection timed out
error: Cannot fetch meta-qt5/meta-qt5 from git://github.com/meta-qt5/meta-qt5
            

fatal: unable to connect to github.com:
github.com[0: 140.82.121.3]: errno=Connection timed out


rauc/meta-rauc:
fatal: unable to connect to github.com:
github.com[0: 140.82.121.3]: errno=Connection timed out

rauc/meta-rauc: sleeping 4.0 seconds before retrying
fatal: unable to connect to github.com:
github.com[0: 140.82.121.4]: errno=Connection timed out


rauc/meta-rauc:
fatal: unable to connect to github.com:
github.com[0: 140.82.121.4]: errno=Connection timed out
error: Cannot fetch rauc/meta-rauc from git://github.com/rauc/meta-rauc
Fetching: 100% (2/2), done in 8m52.380s
Garbage collecting: 100% (2/2), done in 0.083s
Updating files: 100% (5782/5782), done.
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
FileNotFoundError: [Errno 2] No such file or directory: '/home/phyvm/yocto/sources/poky/meta/conf/layer.conf'
Traceback (most recent call last):
  File "/home/phyvm/yocto/sources/meta-phytec/scripts/copy_file_by_priority.py", line 77, in <module>
    main()
  File "/home/phyvm/yocto/sources/meta-phytec/scripts/copy_file_by_priority.py", line 70, in main
    bsp = BSP_BBLayerFile()
  File "/home/phyvm/yocto/sources/meta-phytec/scripts/copy_file_by_priority.py", line 26, in __init__
    priority = self.__get_priority(layer_conf)
  File "/home/phyvm/yocto/sources/meta-phytec/scripts/copy_file_by_priority.py", line 32, in __get_priority
    with open(layer_conf) as lcfile:
FileNotFoundError: [Errno 2] No such file or directory: '/home/phyvm/yocto/sources/poky/meta/conf/layer.conf'
tools/init: 78: cd: can't cd to /home/phyvm/yocto/sources/poky/
tools/init: 79: .: Can't open ./oe-init-build-env
