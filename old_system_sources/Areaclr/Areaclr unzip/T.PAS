program t;
var
 i : word;

 begin
   for i := 1 to paramcount do begin
    writeln(i,' ',paramstr(i));
   end;
 end.