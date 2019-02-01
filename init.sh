if [ $# -eq 0 ]
then
    echo "No arguments supplied"
else
	find ./ -type f -exec sed -i -e 's/sdl_template/$1/g' {} \;
	rm init.sh
fi
