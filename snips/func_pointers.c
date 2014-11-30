typedef struct String_Struct* String;

struct String_Struct {
    char * (*get) (const void* self);
    void (*set) (const void* self, char* value);
    int (*length) (const void* self);
};

char * getString(const void* self);
void setString(const void* self, char* value);
int lengthString(const void* self);

String newString();
