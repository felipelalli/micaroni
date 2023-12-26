#!/bin/bash

# Array of possible characters
chars=( {a..z} {A..Z} {0..9} \! \@ \# \$ \% \& \* \_ )

# Function to check if the password meets the criteria
password_meets_criteria() {
    local password=$1
    [[ $password =~ [a-z] ]] && [[ $password =~ [A-Z] ]] && [[ $password =~ [0-9] ]] && [[ $password =~ [\!@\#\$\%\&\*] ]]
}

# Function to generate the password
generate_password() {
    local password=""
    local count=0
    local index

    # Generate 48 bytes of random data and convert to hexadecimal
    local hex_data=$(openssl rand -hex 48)

    # Iterate over the hexadecimal data
    for (( i=0; i<${#hex_data}; i+=2 )); do
	if [ $count -lt 24 ]; then
	    # Convert two hexadecimal characters to a decimal number
	    local hex_byte="${hex_data:$i:2}"
	    local decimal_byte=$((16#$hex_byte))

	    # Convert byte to a valid index in the array
	    index=$(( decimal_byte % ${#chars[@]} ))
	    password+="${chars[$index]}"
	    ((count++))
	else
	    break
	fi
    done

    echo $password
}

# Loop until a password that meets the criteria is generated
while true; do
    generated_password=$(generate_password)
    if password_meets_criteria "$generated_password"; then
	break
    fi
done

echo "$generated_password"
