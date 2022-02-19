while getopts o:n:f: flag
do
    case "${flag}" in
        o) ofunc=${OPTARG};;
        n) nfunc=${OPTARG};;
        f) filename=${OPTARG};;
    esac
done
echo "Original function: $ofunc";
echo "New function: $nfunc";
echo "File Name: $filename";