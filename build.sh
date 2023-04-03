SRC_PATH=$PWD
PROJ_PATH="/kitty"
PROJ_NAME="KittyLogs"
BUILD_TYPE="Release"

sudo mkdir "$PROJ_PATH"
sudo chown $(whoami) "$PROJ_PATH"
sudo chgrp $(whoami) "$PROJ_PATH"
mkdir "$PROJ_PATH/build"
mkdir "$PROJ_PATH/build/$PROJ_NAME"
cd "$PROJ_PATH/build/$PROJ_NAME"
cmake $SRC_PATH -DKITTY_INSTALL_PATH="$PROJ_PATH" 
make -j6 && make install
