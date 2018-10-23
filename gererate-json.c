/*
Link to frozen library: https://github.com/cesanta/frozen
*/

#include "frozen.c" // library to print and read json files

int main()
{
    FILE *fp = fopen("carData.json", "w");
    struct json_out out = JSON_OUT_FILE(fp);
    json_printf(&out, "{\n");
    json_printf(&out, "\t%Q : %d,\n", "total_mileage", 400);
    json_printf(&out, "\t%Q : %B,\n", "is_parked", 1);
    json_printf(&out, "\t%Q : {\n", "last_trio");
    json_printf(&out, "\t\t%Q : %.1f,\n", "mileage", 25.3);
    json_printf(&out, "\t\t%Q : %.1f\n", "consuption", 13.3);
    json_printf(&out, "\t}\n");
    json_printf(&out, "}");
    return 0;
}