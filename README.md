# bioinformatics

## 1k_splitter.cpp
1. Script to filter fastq reads with certain inline barcodes(found at the start of the read)
2. To modify barcodes add or remove them from line 31  
   Eg. To add more barcodes add   
   if(barcode=="TTCGTGATTC"||barcode=="TTGGAGTGTC"||barcode=="TTGGCATCTC" || barcode="TTTTTTTTTT" )  
   to remove barcode
   if(barcode=="TTCGTGATTC"||barcode=="TTGGAGTGTC")  
3. The current code looks for barcodes of base 10 to modify that change line 33  
   Eg. If I wanted to look for barcodes of length 8  
   string barcode=read.substr(0,8)  
4. Compile the code:  "g++ 1k_splitter.cpp -o splitter"
5. To run: "./splitter name_and_location_file_to_process"
 
 ***
 
 ##
