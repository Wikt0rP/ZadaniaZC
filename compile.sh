if [ -f "$file" ]; then
         filename=$(basename "$file" .c)
         output_path=$(dirname "$file")
         clang -o "${output_path}/${filename}" "$file" -lm
         clang -o "${output_path}/${filename}.exe" "$file" -lm
         if [ $? -eq 0 ]; then
             echo "Compilation successful for $file"
         else
