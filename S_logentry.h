#ifndef S_logentry_H_INCLUDED
#define S_logentry_H_INCLUDED

typedef struct
{
    //int id;
    char date[128];
    char time[128];
    char serviceName[128];
    int gravedad;
    char msg[128];
}S_logEntry;

//void s_logEntry_idInit(int id);
//int s_logEntry_idGenerator();

S_logEntry* s_logEntry_new();
int s_logentry_delete(S_logEntry* this);

/*int s_logEntry_setIdStr(S_logEntry* this,char* idStr);
int s_logEntry_setId(S_logEntry* this,int id);
int s_logEntry_getId(S_logEntry* this,int* id);
int s_logEntry_compareId(void* pS_logEntryA,void* pS_logEntryB);*/

int s_logEntry_setDate(S_logEntry* this,char* date);
int s_logEntry_getDate(S_logEntry* this,char* date);
int s_logEntry_compareDate(void* pS_logEntryA,void* pS_logEntryB);

int s_logEntry_setTime(S_logEntry* this,char* time);
int s_logEntry_getTime(S_logEntry* this,char* time);
int s_logEntry_compareTime(void* pS_logEntryA,void* pS_logEntryB);

int s_logEntry_setServiceName(S_logEntry* this,char* serviceName);
int s_logEntry_getServiceName(S_logEntry* this,char* serviceName);
//int s_logentry_compareServiceName(void* pS_logentryA,void* pS_logentryB);

int s_logEntry_setGravedadStr(S_logEntry* this,char* gravedadStr);
int s_logEntry_setGravedad(S_logEntry* this,int gravedad);
int s_logEntry_getGravedad(S_logEntry* this,int* gravedad);
int s_logEntry_compareGravedad(void* pS_logEntryA,void* pS_logEntryB);

int s_logEntry_setMsg(S_logEntry* this,char* msg);
int s_logEntry_getMsg(S_logEntry* this,char* msg);
int s_logEntry_compareMsg(void* pS_logEntryA,void* pS_logEntryB);

S_logEntry* s_logEntry_newParametros(char* fechaStr,char* timeStr,char* serviceNameStr,char* gravedadStr,char* msgStr);

//FUNCIONES CRITERIO P/INFORMES
int s_logEntry_filtrarGMenor3(void* pElement);
int s_logEntry_filtrarGEsMenor3(void* pElement);
int s_logEntry_filtrarGIgualA3(void* pElement);
int s_logEntry_filtrarGentre4y7(void* pElement);
int s_logEntry_filtrarGMayorA7(void* pElement);

#endif // S_logentry_H_INCLUDED
