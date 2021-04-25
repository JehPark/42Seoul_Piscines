ifconfig -a | grep 'ether ' | awk '{$1=$1}1' | sed 's/ether //'
