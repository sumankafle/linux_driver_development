#! /bin/sh
module="scull"
device="scull"
mode="666"
group=0

function load() {
    sudo insmod ./$module.ko $* || exit 1

    sudo rm -f /dev/${device}[0-2]

    major=$(awk -v device="$device" '$2==device {print $1}' /proc/devices)
    sudo mknod /dev/${device}0 c $major 0
    sudo mknod /dev/${device}1 c $major 1
    sudo mknod /dev/${device}2 c $major 2

    sudo chgrp $group /dev/$device[0-2]
    sudo chmod $mode /dev/$device[0-2]
}

function unload() {
    sudo rm -f /dev/${device}[0-2]
    sudo rmmod $module || exit 1
}

arg=${1:-"load"}
case $arg in
    load)
        load ;;
    unload)
        unload ;;
    reload)
        ( unload )
        load
        ;;
    *)
        echo "Usage: $0 {load | unload | reload}"
        echo "Default is load"
        exit 1
        ;;
esac
