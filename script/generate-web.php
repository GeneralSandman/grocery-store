<?php
date_default_timezone_set('Asia/Shanghai');

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

}
