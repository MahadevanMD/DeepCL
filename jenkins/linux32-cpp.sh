schroot -c trusty_i386 bash jenkins/linux-cpp.sh || exit 1
tar -cjf deepcl-linux32-${version}.tar.bz2 dist

