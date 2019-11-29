<?php
if (count($argv) !== 3) {
    echo "Usage: php input_gen [chord num] [output file]\n";
    exit();
}

$chordNum = $argv[1];
$outputFile = $argv[2];

$pointNum = $chordNum * 2;
$flags = [];
$pickNum = function () use ($pointNum, &$flags) {
    do {
        $num = rand(0, $pointNum - 1);
    } while (!empty($flags[$num]));

    $flags[$num] = true;
    return $num;
};

$file = fopen($outputFile, "w");
fwrite($file, "$pointNum\n");
for ($i = 0; $i < $chordNum; ++$i) {
    fwrite($file, $pickNum()." ".$pickNum()."\n");
}
fwrite($file, "0\n");
fclose($file);
