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

    $destPath = "../grocery-algorithm/剑指Offer/个人题解-markdown";
    $sourcePath = "../grocery-algorithm/剑指Offer/个人题解-源码";
    $sourceFiles = dfsDir($sourcePath);
    $contentPattern = <<< contentPattern
# %s

## link 

%s

## 题解

```go
%s
```

contentPattern;

    $sidebarContent = "";

    foreach($sourceFiles as $sourceFile) {
        echo "$sourceFile\n";
        $tmp = explode("/", $sourceFile);

        $title = $tmp[count($tmp) - 1].".md";
        $destFileName = $tmp[count($tmp) - 1].".md";
        $link = "https://leetcode-cn.com/problem-list/e8X3pBZi/";
        $filePointer = fopen($sourceFile,"rb");
        $solution = fread($filePointer,filesize($sourceFile));
        fclose($filePointer);

        $content = sprintf($contentPattern, $title, $link, $solution);

        file_put_contents($destPath."/".$destFileName, $content);

        $sidebarContent .= sprintf("* [**%s**](%s)\n", $title, $destPath."/".$destFileName);
    }

    file_put_contents("../grocery-algorithm/剑指Offer/_sidebar.md", $sidebarContent);

}
