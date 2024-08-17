#!/bin/env bash

pdf_files=()

for file in *.pdf; do 
    pdf_files+=("$file")
done;

pdfunite "${pdf_files[@]}" "output.pdf"
# pdfunite "${pdf_files[*]}" "output.pdf"
