
Debian
====================
This directory contains files used to package kraitd/krait-qt
for Debian-based Linux systems. If you compile kraitd/krait-qt yourself, there are some useful files here.

## krait: URI support ##


krait-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install krait-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your kraitqt binary to `/usr/bin`
and the `../../share/pixmaps/krait128.png` to `/usr/share/pixmaps`

krait-qt.protocol (KDE)

