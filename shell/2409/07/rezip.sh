# there are still some problems so that i cannot give u an
# executable bash script, but u can find some useful option 
# and command about ZIP and UNZIP

shopt -s globstar

# unzip all zip files with their own name 
# -q mean quiet, don't print messages but errors
# -d , to specify a output dir
for file in **/*.zip; do
    unzip -q "$file" -d "${file%.zip}" && rm "$file"
done


# zip all dirs with a same Password, and u needn't 
# input them again and again 
# -r means recurse
# -e means zip with password
# -num means zip level, 0 -> 9 means lightest -> strongest
# -q means quiet
# -P "password" to specify a password
for dir in *; do
    zip -re0qP "password" "${dir}.zip" "$dir" && rm -r "$dir"
done
