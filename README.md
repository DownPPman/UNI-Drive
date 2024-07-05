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
