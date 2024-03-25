ans_file="ans.txt"
if [ -f "ans_file" ]; then
  read -r ANS < ans_file
else
    ANS=0
fi

declare -a hist=()

while true;
do
    clear
    read -p ">> " a b c
    if [ "$a" == "ANS" ]; then
        a=$ANS
    fi
    if [ "$c" == "ANS" ]; then
        c=$ANS
    fi
    if [ "$a" == "EXIT" ];
    then
        break
    elif [ "$a" == "HIST" ]
    then
        for ((i=0; i<${#hist[@]}; i++)); do
          echo "${hist[$i]}"
        done
        read -n 1 -s -r -p ""
        continue
    fi
    if ! [[ "$a" =~ ^[0-9]+(\.[0-9]+)?$ ]] || ! [[ "$c" =~ ^[0-9]+(\.[0-9]+)?$ ]]; then
        echo "SYNTAX ERROR"
        read -n 1 -s -r -p ""
        continue
    fi
    if ! [ "$b" == "+" ] && ! [ "$b" == "-" ] && ! [ "$b" == "*" ] && ! [ "$b" == "/" ] && ! [ "$b" == "%" ]; then
        echo "SYNTAX ERROR"
        read -n 1 -s -r -p ""
        continue
    fi
    case $b in
        +) res=$(echo "$a + $c" | bc)
        ;;
        -) res=$(echo "$a - $c" | bc)
        ;;
        \*) res=$(echo "$a * $c" | bc)
        ;;
        %)
        if [ "$c" -eq "0" ]; then
          echo "MATH ERROR"
          read -n 1 -s -r -p ""
          continue
        fi
        if [ "$a" -lt "$c" ]; then
          res=$a
        else
        res=$(echo "$a % $c" | bc)
        fi
        ;;
        /)
        if [ "$c" -eq "0" ]; then
          echo "MATH ERROR"
          read -n 1 -s -r -p ""
          continue
        fi
        if [ "$a" -lt "$c" ]; then
          echo -n "0"
        fi
        res=$(echo "scale=2; $a / $c" | bc)
        ;;
    esac
    hist+=("$a $b $c = $res")
    echo "$res"
    ANS=$res
    echo $ANS > ans_file
    read -n 1 -s -r -p ""
done


