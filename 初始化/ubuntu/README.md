# Ubuntu 18.04
## gedit + gcin 畫面出問題

修改 them

    gsettings set org.gnome.desktop.interface gtk-theme 'Adwaita-dark'

## bridge ubuntu
    sudo ubuntu-drivers autoinstall
    sudo apt-get install bridge-utils
    sudo apt-get install nvidia-driver-450
    sudo apt-get install tlp
    sudo systemctl enable tlp
    sudo tlp-stat
    sudo apt-get install powertop
## 中文輸入法
rime
https://www.ubuntu-tw.org/modules/newbb/viewtopic.php?post_id=290350
