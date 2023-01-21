function clear() {
  cd src/commands/ && ls | grep .o | xargs rm
}


function compile() {
  cd src/commands/

  commands=$(ls | grep .c)

  commands_replaced=(${commands//".c"/".o"})
  commands_replaced_with_c=(${commands// /})

  for i in "${!commands_replaced[@]}";
  do
    echo "compiling ${commands_replaced_with_c[$i]}..."
    gcc -Werror -Wall -Wextra ${commands_replaced_with_c[$i]} -o ${commands_replaced[$i]}
    echo "Compiled : ${commands_replaced_with_c[$i]}"
  done
}

clear
compile