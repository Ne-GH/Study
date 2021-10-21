#!usr/bin/bash
for i in {1..5}
do 
	ping -c1 baidu.com &>/dev/null
	if [ $? -eq 0 ]; then
		echo "ok"
	else
		echo "not can"
	fi
done
