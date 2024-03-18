s/[a-zA-Z]\{3\}[0-9]\{3\}/XYZ000/g
s/@[0-9]\{8\}/@XXXXXXXX/g
s/[AaBbCcDdFf][+-]/X/g
s/[0-4]\.[0-9]\{1,3\}/X.X/g
s/^X*/d/
$d
$d
