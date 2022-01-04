<?php
date_default_timezone_set('Asia/Shanghai');
include "base.php";

// php generate-web.php --command=all
// php generate-web.php --command=all

main();
function main()
{
    $opt = array(
        'command:'
    );
    $param = getopt('', $opt);
    $command = $param["command"];


    switch ($command) {
        case "all":
            break;
        case "grocery-algorithm":
            generateGroceryAlgorithm();
            break;
        case "grocery-blog":
            break;
        case "grocery-book":
            break;
        case "grocery-note":
            break;
    }
}

function generateGroceryAlgorithm() {

    $path = "../grocery-algorithm/剑指Offer/个人题解-源码";

    $files = dfsDir($path);

    $contentPattern = <<< contentPattern
# %s

## link %s

## 题解

%s

contentPattern;

    foreach($files as $filePath) {
        echo "$filePath\n";

        $title = $filePath;
        $link = "link";
        $filePointer = fopen($filePath,"rb");
        $solution = fread($filePointer,filesize($filePath));
        fclose($fp);

        $content = sprintf($contentPattern, $title, $link, $solution);
    } 
}
