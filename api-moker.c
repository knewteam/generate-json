/*
Link to frozen library: https://github.com/cesanta/frozen
*/

#define GET_VARIABLE_NAME(Variable) (#Variable)
#include "frozen.c" // library to print and read json files


//destiny position
float destiny_latitude = -8.0340303;
float destiny_longitude = -34.84558;

int is_parked = 1;

//last trip
float consuption = 13.3;
float mileage = 25.3;

//position
float position_latitude = -8.05;
float position_longitude = -34.86;

char *security_phrase = "só queria ser liberada";
float total_mileage = 400;

char *failures[100] = {"Nível de óleo baixo, você deve trocar o óleo e verificar se há vazamentos",
                    "falha no nível de bateria, posso agendar uma revisão?"};
void generateJson()
{
    FILE *fp = fopen("api.json", "w");
    struct json_out out = JSON_OUT_FILE(fp);
    json_printf(&out, "{\n");
    json_printf(&out, "\tcar_status : {\n");
    json_printf(&out, "\t\tfailures : { \n");
    json_printf(&out, "\t\t\tfailure_1 : %Q,\n", failures[0]);
    json_printf(&out, "\t\t\tfailure_2 : %Q\n", failures[1]);
    json_printf(&out, "\t\t}\n");
    json_printf(&out, "\t},\n");
    json_printf(&out, "\tdestiny_positions : {\n");
    json_printf(&out, "\t\tlatitude : %.2f,\n", position_latitude);
    json_printf(&out, "\t\tlongitude : %.2f\n", position_longitude);
    json_printf(&out, "\t},\n");
    json_printf(&out, "\tis_parked : %B,\n", is_parked);
    json_printf(&out, "\tlast_trip : {\n");
    json_printf(&out, "\t\tconsuption : %.2f,\n", consuption);
    json_printf(&out, "\t\tmiliage : %.2f\n",mileage);
    json_printf(&out, "\t},\n");
    json_printf(&out, "\tposition : {\n");
    json_printf(&out, "\t\tlatitude : %.2f,\n",position_latitude);
    json_printf(&out, "\t\tlongitude : %.2f\n",position_longitude);
    json_printf(&out, "\t},\n");
    json_printf(&out, "\tsecurity_phrase : %Q,\n",security_phrase);
    json_printf(&out, "\ttotal_mileage : %.2f \n", total_mileage);
    json_printf(&out, "}\n");
    return;
}

int main()
{
    generateJson();
    return 0;
}
