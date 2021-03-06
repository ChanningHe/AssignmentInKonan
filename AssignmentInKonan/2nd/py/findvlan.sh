#!/bin/bash
function checknetwork()
{
    local timeout=1

    local target=www.google.com

    #获取响应状态码
    local ret_code=`curl -I -s --connect-timeout ${timeout} ${target} -w %{http_code} | tail -n1`

    if [ "x$ret_code" = "x200" ]; then
        
        return 1
    else
        #cant access internet
        return 0
    fi

    return 0
}

for i in `seq 1 4095`
do
    uci set network.wan.ifname=eth1.$i  #修改eth
    #uci set network.wan.username=
    #uci set network.wan.password=
    uci commit
    sleep 2s

    checknetwork
    if [ $? -eq 0 ];then
        echo "checking vlan $i"
        echo "cant access internet！"
        #exit -1
    else
    #cat $i > ./valn.txt
    echo "the vlan is $i" 
    break;
    fi

done

