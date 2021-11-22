//COMPILE WITH: 'gcc ./shape.c  -w  -w /opt/bah/libs/libgc.a -lpthread -lm -lGL -lglut -lGLU'

#include "/opt/bah/libs/include/gc.h"

#define noCheck(v) v
#define array(type)	struct{	type *data; long int length; long int elemSize; }
typedef array(char*)* __BAH_ARR_TYPE_cpstring;
long int __BAH__main(__BAH_ARR_TYPE_cpstring);

int main(int argc, char ** argv) {
GC_INIT();
array(char*) * args = GC_MALLOC(sizeof(array(char*)));
args->data = GC_MALLOC(sizeof(char*)*argc);
memcpy(args->data, argv, sizeof(char*)*argc);
args->elemSize = sizeof(char*);
args->length = argc;
return __BAH__main((__BAH_ARR_TYPE_cpstring)args);
};
#define main(v) __BAH__main(v)
#include <signal.h>
#include <string.h>
#define null (void *)0
#define true (int)1
#define false (int)0
#include </opt/bah/libs/include/gc.h>
#include <sys/mman.h>
#define SIZE_OF_INT 8
#define SIZE_OF_CHAR 1
#define SIZE_OF_INT32 4
#define SIZE_OF_FLOAT32 4
#define SIZE_OF_FLOAT 8
long int len(void * a){
long int i =  0;
noCheck( array ( void* ) *arr = a );
noCheck( i = arr -> length );
return i;
};
void fastZeroSet(void * p,long int s){
long int byte =  0;
long int* v;
long int i =  0;
while ((i<s)) {
if ((i + 8>s)) {
memset(noCheck( p + i ),0,s - i);
break;
}
v =  noCheck( p + i );
*v =  byte;
i =  i + 8;
};
};
void * memoryAlloc(long int s){
void * p =  GC_MALLOC(s);
return p;
};
void destroy(void * a){
GC_FREE(a);
};
void clear(void * a){
noCheck( array ( void* ) *arr = a );
noCheck( destroy ( arr -> data ) );
noCheck( arr -> data = memoryAlloc ( sizeof ( 0 ) ) );
noCheck( arr -> length = 0 );
};
void append(void * a,void * b){
noCheck( array ( void* ) *arrA = a );
noCheck( array ( void* ) *arrB = b );
long int lenA =  0;
long int lenB =  0;
long int realSizeA =  0;
long int realSizeB =  0;
noCheck( lenA = len ( arrA ) );
noCheck( lenB = len ( arrB ) );
if ((lenB==0)) {
return ;
}
if ((lenA==0)) {
noCheck( arrA -> data = arrB -> data );
noCheck( arrA -> length = arrB -> length );
return ;
}
noCheck( realSizeA = lenA * arrA -> elemSize );
noCheck( realSizeB = lenB * arrB -> elemSize );
void * buff =  memoryAlloc(realSizeA + realSizeB + 32);
noCheck( memcpy ( buff , arrA -> data , realSizeA ) );
noCheck( memcpy ( buff + lenA , arrB -> data , realSizeB ) );
noCheck( arrA -> length = lenA + lenB );
noCheck( arrA -> data = buff );
};
void copy(void * a,void * b){
noCheck( array ( void* ) *arrA = a );
noCheck( array ( void* ) *arrB = b );
long int lenB =  0;
long int realSizeB =  0;
noCheck( lenB = len ( arrB ) );
noCheck( realSizeB = lenB * arrB -> elemSize );
noCheck( arrA -> data = memoryAlloc ( realSizeB ) );
noCheck( memcpy ( arrA -> data , arrB -> data , realSizeB ) );
noCheck( arrA -> length = arrB -> length );
};
void * memoryRealloc(void * p,long int s){
void * np =  GC_REALLOC(p,s);
return np;
};
#define PROT_READ 1
#define PROT_WRITE 2
#define PROT_READWRITE 3
#define MAP_SHARED 1
#define MAP_ANONYMOUS 32
void * sharedMemory(long int size){
if ((size==0)) {
size =  4096;
}
void * r =  mmap(0,size,PROT_READ + PROT_WRITE,MAP_SHARED + MAP_ANONYMOUS,-1,0);
return r;
};
void allocateArray(void * arr,long int nbElems){
noCheck( array ( void* ) *a = arr );
noCheck( a -> length = nbElems );
noCheck( a -> data = memoryAlloc ( nbElems * a -> elemSize ) );
};
typedef array(char)* __BAH_ARR_TYPE_char;
__BAH_ARR_TYPE_char ser(void * a);
__BAH_ARR_TYPE_char __serialize(void * a,long int s){
char * r =  memoryAlloc(s + 9);
memcpy(r,&s,8);
memcpy(noCheck( r + 8 ),a,s);
long int l =  s + 1;
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
noCheck( arr -> length = s + 8 );
noCheck( arr -> elemSize = 1 );
noCheck( arr -> data = r );
return arr;
};
long int serlen(__BAH_ARR_TYPE_char data){
array(char)* sarr = memoryAlloc(sizeof(array(char)));

sarr->length = 8;
sarr->elemSize = sizeof(char);
sarr->data = memoryAlloc(sizeof(char) * 50);sarr->data[0] = data->data[0];
sarr->data[1] = data->data[1];
sarr->data[2] = data->data[2];
sarr->data[3] = data->data[3];
sarr->data[4] = data->data[4];
sarr->data[5] = data->data[5];
sarr->data[6] = data->data[6];
sarr->data[7] = data->data[7];
long int* sptr =  noCheck( sarr -> data );
return *sptr;
};
void * unser(__BAH_ARR_TYPE_char data){
long int sptr =  serlen(data);
void * r =  memoryAlloc(sptr);
memcpy(r,noCheck( data -> data + 8 ),sptr);
return r;
};
char * concatCPSTRING(char * a,char * b){
long int lenA =  strlen(a);
long int lenB =  strlen(b);
char * r =  memoryAlloc(lenA + lenB + 1);
strncpy(r,a,lenA);
strcat(r,b);
return r;
};
char * __STR(char * a){
long int lenA =  strlen(a);
char * r =  memoryAlloc(lenA + 1);
strncpy(r,a,lenA);
return r;
};
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
char cpstringCharAt(char * s,long int i){
char c =  (char)0;
noCheck( c = s [ i ] );
return c;
};
char * charToString(char c){
char * s =  memoryAlloc(2);
strncpy(s,(char *)&c,1);
return s;
};
long int isUpper(char c){
if ((c>(char)64)) {
if ((c<(char)91)) {
return 1;
}
}
return 0;
};
long int isLower(char c){
if ((c>(char)96)) {
if ((c<(char)123)) {
return 1;
}
}
return 0;
};
long int isLetter(char s){
if (isUpper(s)) {
return 1;
}
if (isLower(s)) {
return 1;
}
return 0;
};
long int isNumber(char c){
if ((c>(char)47)) {
if ((c<(char)58)) {
return 1;
}
}
return 0;
};
long int isAlphaNumeric(char s){
if (isLetter(s)) {
return 1;
}
if (isNumber(s)) {
return 1;
}
return 0;
};
long int isSpace(char c){
if ((c==(char)32)) {
return 1;
}
if ((c==(char)9)) {
return 1;
}
if ((c==(char)10)) {
return 1;
}
if ((c==(char)11)) {
return 1;
}
if ((c==(char)13)) {
return 1;
}
return 0;
};
struct string {
char * content;
long int length;
void(*set)(struct string* this,char * s);
void(*append)(struct string* this,char * s);
void(*prepend)(struct string* this,char * s);
char(*charAt)(struct string* this,long int i);
long int(*compare)(struct string* this,char * s);
char *(*str)(struct string* this);
void(*replace)(struct string* this,char * nd,char * rl);
long int(*count)(struct string* this,char * need);
long int(*hasPrefix)(struct string* this,char * need);
long int(*hasSuffix)(struct string* this,char * need);
void(*trim)(struct string* this);
void(*trimLeft)(struct string* this,long int s);
void(*trimRight)(struct string* this,long int s);
};
void string__set(struct string* this,char * s){
this->length =  strlen(s);
this->content =  (char *)memoryAlloc(this->length + 1);
strcpy(this->content,s);
};
void string__append(struct string* this,char * s){
this->length =  this->length + strlen(s);
char * tmpS =  (char *)memoryRealloc((void *)this->content,this->length);
if (((long int)tmpS==0)) {
tmpS =  (char *)memoryAlloc(this->length);
strncpy(tmpS,this->content,this->length);
}
strcat(tmpS,s);
this->content =  tmpS;
};
void string__prepend(struct string* this,char * s){
char * tmpS =  this->content;
this->length =  this->length + strlen(s);
this->content =  (char *)memoryAlloc(this->length + 1);
strcpy(this->content,s);
strcat(this->content,tmpS);
};
char string__charAt(struct string* this,long int i){
char c =  (char)0;
if ((i<this->length)) {
noCheck( c = this -> content [ i ] );
return c;
}
return c;
};
long int string__compare(struct string* this,char * s){
long int r =  strcmp(this->content,s);
if ((r==0)) {
return 1;
}
return 0;
};
char * string__str(struct string* this){
char * r =  this->content;
return r;
};
void string__replace(struct string* this,char * nd,char * rl){
struct string needle =  {};
needle.set = string__set;
needle.append = string__append;
needle.prepend = string__prepend;
needle.charAt = string__charAt;
needle.compare = string__compare;
needle.str = string__str;
needle.replace = string__replace;
needle.set((struct string*)&needle,nd);
struct string repl =  {};
repl.set = string__set;
repl.append = string__append;
repl.prepend = string__prepend;
repl.charAt = string__charAt;
repl.compare = string__compare;
repl.str = string__str;
repl.replace = string__replace;
repl.set((struct string*)&repl,rl);
long int i =  0;
long int si =  0;
array(char)* replcBuff = memoryAlloc(sizeof(array(char)));

replcBuff->length = 0;
replcBuff->elemSize = sizeof(char);
array(char)* buff = memoryAlloc(sizeof(array(char)));

buff->length = 0;
buff->elemSize = sizeof(char);
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
char rc =  needle.charAt((struct string*)&needle,si);
if ((c==rc)) {
si =  si + 1;

{
long nLength = len(replcBuff);
if (replcBuff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(replcBuff->data, (nLength+50)*sizeof(char));
replcBuff->data = newPtr;
}
replcBuff->data[len(replcBuff)] =  c;
replcBuff->length = nLength+1;
} else {
replcBuff->data[len(replcBuff)] =  c;
};
};
}
else {
if ((len(replcBuff)>0)) {
si =  0;
append(buff,replcBuff);
clear(replcBuff);
}

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] =  c;
buff->length = nLength+1;
} else {
buff->data[len(buff)] =  c;
};
};
}
if ((si==needle.length)) {
clear(replcBuff);
long int ii =  0;
while ((ii<repl.length)) {
long int a =  ii;

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] =  repl.charAt((struct string*)&repl,ii);
buff->length = nLength+1;
} else {
buff->data[len(buff)] =  repl.charAt((struct string*)&repl,ii);
};
};
ii =  ii + 1;
};
si =  0;
}
i =  i + 1;
};
char * r =  "";
noCheck( r = buff -> data );
if ((len(replcBuff)>0)) {
char * replbuffStr;
noCheck( replbuffStr = replcBuff -> data );
r =  concatCPSTRING(r,replbuffStr);
}
if (((void *)r!=null)) {
this->set((struct string*)this,r);
}
};
long int string__count(struct string* this,char * need){
long int i =  0;
long int count =  0;
struct string needle =  {};
needle.set = string__set;
needle.append = string__append;
needle.prepend = string__prepend;
needle.charAt = string__charAt;
needle.compare = string__compare;
needle.str = string__str;
needle.replace = string__replace;
needle.count = string__count;
needle.set((struct string*)&needle,need);
long int countIndex =  0;
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
char sc =  needle.charAt((struct string*)&needle,countIndex);
if ((c==sc)) {
countIndex =  countIndex + 1;
}
else {
countIndex =  0;
}
if ((countIndex==needle.length)) {
count =  count + 1;
countIndex =  0;
}
i =  i + 1;
};
return count;
};
long int string__hasPrefix(struct string* this,char * need){
long int i =  0;
long int nl =  strlen(need);
if ((this->length<nl)) {
return 0;
}
while ((i<nl)) {
char c =  this->charAt((struct string*)this,i);
char sc =  cpstringCharAt(need,i);
if ((c!=sc)) {
return 0;
}
i =  i + 1;
};
return 1;
};
long int string__hasSuffix(struct string* this,char * need){
long int nl =  strlen(need);
if ((this->length<nl)) {
return 0;
}
long int i =  this->length - nl;
long int needleIndex =  0;
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
char sc =  cpstringCharAt(need,needleIndex);
if ((c!=sc)) {
return 0;
}
needleIndex =  needleIndex + 1;
i =  i + 1;
};
return 1;
};
void string__trim(struct string* this){
if ((this->length==0)) {
return ;
}
char fc =  this->charAt((struct string*)this,0);
if ((isSpace(fc)==0)) {
return ;
}
long int i =  0;
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
if ((isSpace(c)==0)) {
break;
}
i =  i + 1;
};
if ((i>0)) {
this->length =  this->length - i;
char * tmpS =  memoryAlloc(this->length + 1);
memcpy(tmpS,noCheck( this->content + i ),this->length + 1);
this->content =  tmpS;
}
};
void string__trimLeft(struct string* this,long int s){
long int nSize =  this->length - s;
void * tmpS =  memoryAlloc(nSize);
memcpy(tmpS,noCheck( this->content + s ),nSize);
this->content =  tmpS;
this->length =  nSize;
};
void string__trimRight(struct string* this,long int s){
long int nSize =  this->length - s;
void * tmpS =  memoryAlloc(nSize);
memcpy(tmpS,this->content,nSize);
this->content =  tmpS;
this->length =  nSize;
};
struct string string(char * s){
struct string a =  {};
a.set = string__set;
a.append = string__append;
a.prepend = string__prepend;
a.charAt = string__charAt;
a.compare = string__compare;
a.str = string__str;
a.replace = string__replace;
a.count = string__count;
a.hasPrefix = string__hasPrefix;
a.hasSuffix = string__hasSuffix;
a.trim = string__trim;
a.trimLeft = string__trimLeft;
a.trimRight = string__trimRight;
a.content =  (char *)0;
a.length =  0;
a.set((struct string*)&a,s);
return a;
};
char * arrToStr(__BAH_ARR_TYPE_char arr){
long int strLen =  len(arr);
char * str =  memoryAlloc(strLen + 1);
noCheck( memcpy ( str , arr -> data , strLen ) );
return str;
};
__BAH_ARR_TYPE_char strToArr(char * str){
long int strLen =  strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
noCheck( arr -> data = memoryAlloc ( strLen + 1 ) );
noCheck( memcpy ( arr -> data , str , strLen ) );
noCheck( arr -> elemSize = 1 );
noCheck( arr -> length = strLen );
return arr;
};
char * arrAsStr(__BAH_ARR_TYPE_char arr){
char * r =  "";
noCheck( r = arr -> data );
return r;
};
__BAH_ARR_TYPE_char strAsArr(char * str){
long int l =  strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
noCheck( arr -> length = l );
noCheck( arr -> elemSize = 1 );
noCheck( arr -> data = str );
return arr;
};
struct string intToString(long int i){
char * buff =  memoryAlloc(65);
void * ptri =  (void *)i;
sprintf(buff,"%d",ptri);
struct string r =  string(buff);
return r;
};
char * intToStr(long int i){
char * buff =  memoryAlloc(50);
sprintf(buff,"%ld",i);
return buff;
};
char * floatToStr(double f){
char * buff =  memoryAlloc(50);
sprintf(buff,"%lf",f);
return buff;
};
long int strToInt(char * s){
return atol(s);
};
double strToFloat(char * s){
return strtod(s,null);
};
long int stringToInt(struct string s){
long int i =  atol(s.content);
return i;
};
typedef array(struct string)* __BAH_ARR_TYPE_string;
__BAH_ARR_TYPE_string splitString(struct string s,char * sp){
struct string sep =  string(sp);
array(struct string)* res = memoryAlloc(sizeof(array(struct string)));

res->length = 0;
res->elemSize = sizeof(struct string);
struct string sepBuffer =  string("");
long int sepIndex =  0;
long int i =  0;
struct string replcBuff =  string("");
array(char)* tmpString = memoryAlloc(sizeof(array(char)));

tmpString->length = 0;
tmpString->elemSize = sizeof(char);
while ((i<s.length)) {
char c =  s.charAt((struct string*)&s,i);
char sepc =  sep.charAt((struct string*)&sep,sepIndex);
if ((c==sepc)) {
sepIndex =  sepIndex + 1;
replcBuff.append((struct string*)&replcBuff,charToString(c));
}
else {
if ((sepIndex>0)) {
sepIndex =  0;
replcBuff.append((struct string*)&replcBuff,charToString(c));
long int ii =  0;
while ((ii<replcBuff.length)) {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
};
};
ii =  ii + 1;
};
replcBuff.set((struct string*)&replcBuff,"");
}
else {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] =  c;
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] =  c;
};
};
}
}
if ((sepIndex==sep.length)) {
replcBuff.set((struct string*)&replcBuff,"");
struct string* elem = memoryAlloc(sizeof(struct string));
elem->set = string__set;
elem->append = string__append;
elem->prepend = string__prepend;
elem->charAt = string__charAt;
elem->compare = string__compare;
elem->str = string__str;
elem->replace = string__replace;
elem->count = string__count;
elem->hasPrefix = string__hasPrefix;
elem->hasSuffix = string__hasSuffix;
elem->trim = string__trim;
elem->trimLeft = string__trimLeft;
elem->trimRight = string__trimRight;
elem->set((struct string*)elem,arrToStr(tmpString));
long int lenRes =  len(res);

{
long nLength = lenRes;
if (res->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(res->data, (nLength+50)*sizeof(struct string));
res->data = newPtr;
}
res->data[lenRes] =  *elem;
res->length = nLength+1;
} else {
res->data[lenRes] =  *elem;
};
};
clear(tmpString);
sepIndex =  0;
}
i =  i + 1;
};
if ((replcBuff.length>0)) {
long int ii =  0;
while ((ii<replcBuff.length)) {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
};
};
ii =  ii + 1;
};
}
if ((len(tmpString)>0)) {
struct string* elem = memoryAlloc(sizeof(struct string));
elem->set = string__set;
elem->append = string__append;
elem->prepend = string__prepend;
elem->charAt = string__charAt;
elem->compare = string__compare;
elem->str = string__str;
elem->replace = string__replace;
elem->count = string__count;
elem->hasPrefix = string__hasPrefix;
elem->hasSuffix = string__hasSuffix;
elem->trim = string__trim;
elem->trimLeft = string__trimLeft;
elem->trimRight = string__trimRight;
elem->set((struct string*)elem,arrToStr(tmpString));
long int lenRes =  len(res);

{
long nLength = lenRes;
if (res->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(res->data, (nLength+50)*sizeof(struct string));
res->data = newPtr;
}
res->data[lenRes] =  *elem;
res->length = nLength+1;
} else {
res->data[lenRes] =  *elem;
};
};
}
return res;
};
struct string joinString(__BAH_ARR_TYPE_string a,char * sep){
long int i =  0;
struct string s =  string("");
long int max =  len(a) - 1;
while ((i<len(a))) {
struct string e =  a->data[i];
if ((e.length==0)) {
i =  i + 1;
continue;
}
struct string tmpS =  string(e.str((struct string*)&e));
if ((i!=max)) {
tmpS.append((struct string*)&tmpS,sep);
}
s.append((struct string*)&s,tmpS.str((struct string*)&tmpS));
i =  i + 1;
};
return s;
};
char * splitStringBefore(struct string s,char * sp){
struct string sep =  string(sp);
if ((sep.length>=s.length)) {
return "";
}
long int sepIndex =  0;
long int foundIndex =  0;
long int i =  0;
while ((i<s.length)) {
char c =  s.charAt((struct string*)&s,i);
char sc =  sep.charAt((struct string*)&sep,sepIndex);
if ((c==sc)) {
if ((sepIndex==0)) {
foundIndex =  i - 1;
}
sepIndex =  sepIndex + 1;
if ((sepIndex==sep.length)) {
long int max =  s.length - foundIndex - 1;
s.trimRight((struct string*)&s,max);
return s.str((struct string*)&s);
}
}
else {
foundIndex =  0;
sepIndex =  0;
}
i =  i + 1;
};
return "";
};
struct string toLower(struct string s){
array(char)* ns = memoryAlloc(sizeof(array(char)));

ns->length = 0;
ns->elemSize = sizeof(char);
long int i =  0;
while ((i<s.length)) {
char c =  s.charAt((struct string*)&s,i);
if (isUpper(c)) {
c =  c + (char)32;
}

{
long nLength = len(ns);
if (ns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(ns->data, (nLength+50)*sizeof(char));
ns->data = newPtr;
}
ns->data[len(ns)] =  c;
ns->length = nLength+1;
} else {
ns->data[len(ns)] =  c;
};
};
i =  i + 1;
};
return string(arrToStr(ns));
};
int strHasPrefix(char * s,char * need){
long int i =  0;
long int nl =  strlen(need);
long int sl =  strlen(s);
if ((sl<nl)) {
return false;
}
while ((i<nl)) {
char c =  cpstringCharAt(s,i);
char sc =  cpstringCharAt(need,i);
if ((c!=sc)) {
return false;
}
i =  i + 1;
};
return true;
};
void strTrimLeft(char ** s,long int i){
*s =  noCheck( *s + i );
};
void strTrimRight(char ** s,long int i){
long int ls =  strlen(*s);
char * ns =  memoryAlloc(ls - i);
memcpy(ns,*s,ls - i);
*s =  ns;
};
void strTrim(char ** s){
long int l =  strlen(*s);
long int i =  0;
while ((i<l)) {
char c =  cpstringCharAt(*s,i);
if ((isSpace(c)==0)) {
break;
}
i =  i + 1;
};
*s =  noCheck( *s + i );
};
long int strCount(char * src,char * needle){
long int i =  0;
long int count =  0;
long int countIndex =  0;
long int sl =  strlen(src);
long int nl =  strlen(needle);
while ((i<sl)) {
char c =  cpstringCharAt(src,i);
char sc =  cpstringCharAt(needle,countIndex);
if ((c==sc)) {
countIndex =  countIndex + 1;
}
else {
countIndex =  0;
}
if ((countIndex==nl)) {
count =  count + 1;
countIndex =  0;
}
i =  i + 1;
};
return count;
};
char * stdinput(long int len){
char * buff =  memoryAlloc(len);
fgets(buff,len,noCheck( stdin ));
return buff;
};
void print(char * s){
write((void *)1,s,strlen(s));
};
void println(char * s){
write((void *)1,s,strlen(s));
write((void *)1,"\n",1);
};
void panic(char * e){
if (strlen(e)) {
println(e);
exit(1);
}
};
struct fileStream {
FILE* handle;
long int(*isValid)(struct fileStream* this);
void(*open)(struct fileStream* this,char * path,char * mode);
void(*close)(struct fileStream* this);
long int(*getPos)(struct fileStream* this);
void(*setPos)(struct fileStream* this,long int i);
long int(*getSize)(struct fileStream* this);
void(*rewind)(struct fileStream* this);
char(*getChar)(struct fileStream* this);
void(*setChar)(struct fileStream* this,char c);
void(*createFile)(struct fileStream* this,char * path);
long int(*writeFile)(struct fileStream* this,char * content);
void(*writePtr)(struct fileStream* this,void * a,long int s);
long int(*readPtr)(struct fileStream* this,void * a,long int s);
char *(*readContent)(struct fileStream* this);
array(char)*(*readBytes)(struct fileStream* this);
void(*writeBytes)(struct fileStream* this,array(char)* d);
};
long int fileStream__isValid(struct fileStream* this){
if ((this->handle==null)) {
return 0;
}
return 1;
};
void fileStream__open(struct fileStream* this,char * path,char * mode){
this->handle =  fopen(path,mode);
};
void fileStream__close(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
return ;
}
fclose(this->handle);
};
long int fileStream__getPos(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
return 0;
}
return ftell(this->handle);
};
void fileStream__setPos(struct fileStream* this,long int i){
if ((this->isValid((struct fileStream*)this)==0)) {
return ;
}
fseek(this->handle,i,0);
};
long int fileStream__getSize(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
return -1;
}
long int oldPos =  this->getPos((struct fileStream*)this);
fseek(this->handle,0,2);
long int size =  ftell(this->handle);
this->setPos((struct fileStream*)this,oldPos);
return size;
};
void fileStream__rewind(struct fileStream* this){
rewind(this->handle);
};
char fileStream__getChar(struct fileStream* this){
char c =  getc(this->handle);
return c;
};
void fileStream__setChar(struct fileStream* this,char c){
fputc(c,this->handle);
};
void fileStream__createFile(struct fileStream* this,char * path){
this->open((struct fileStream*)this,path,"w");
this->close((struct fileStream*)this);
};
long int fileStream__writeFile(struct fileStream* this,char * content){
if ((this->isValid((struct fileStream*)this)==0)) {
return -1;
}
fputs(content,this->handle);
return 1;
};
void fileStream__writePtr(struct fileStream* this,void * a,long int s){
fwrite(a,s,1,this->handle);
};
long int fileStream__readPtr(struct fileStream* this,void * a,long int s){
return fread(a,s,1,this->handle);
};
char * fileStream__readContent(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
return "invalid";
}
long int sz =  this->getSize((struct fileStream*)this);
char * r =  memoryAlloc(sz + 1);
long int l =  fread(r,1,sz,this->handle);
if ((sz!=l)) {
array(char)* rarr =  strAsArr(r);

{
long nLength = l;
if (rarr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(rarr->data, (nLength+50)*sizeof(char));
rarr->data = newPtr;
}
rarr->data[l] =  (char)0;
rarr->length = nLength+1;
} else {
rarr->data[l] =  (char)0;
};
};
}
return r;
};
__BAH_ARR_TYPE_char fileStream__readBytes(struct fileStream* this){
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
allocateArray(r,this->getSize((struct fileStream*)this));
this->readPtr((struct fileStream*)this,noCheck( r -> data ),len(r));
return r;
};
void fileStream__writeBytes(struct fileStream* this,__BAH_ARR_TYPE_char d){
this->writePtr((struct fileStream*)this,noCheck( d -> data ),len(d));
};
struct fileMap {
long int handle;
long int size;
char *(*open)(struct fileMap* this,char * fileName);
long int(*isValid)(struct fileMap* this);
void(*close)(struct fileMap* this);
};
char * fileMap__open(struct fileMap* this,char * fileName){
this->handle =  open(fileName,noCheck( O_RDWR ),noCheck( S_IRUSR | S_IWUSR ));
struct stat sb =  {};
fstat(this->handle,&sb);
this->size =  sb.st_size;
char * file =  mmap(0,sb.st_size,noCheck( PROT_READ | PROT_WRITE ),noCheck( MAP_SHARED ),this->handle,0);
return file;
};
long int fileMap__isValid(struct fileMap* this){
if ((this->handle<0)) {
return 0;
}
return 1;
};
void fileMap__close(struct fileMap* this){
close(this->handle);
};
__BAH_ARR_TYPE_cpstring listFiles(char * dir){
array(char *)* files = memoryAlloc(sizeof(array(char *)));

files->length = 0;
files->elemSize = sizeof(char *);
DIR* d =  opendir(dir);
struct dirent* file =  readdir(d);
while ((file!=null)) {
long int lf =  len(files);
if ((strcmp(file->d_name,".")==0)) {
file =  readdir(d);
continue;
}
if ((strcmp(file->d_name,"..")==0)) {
file =  readdir(d);
continue;
}

{
long nLength = lf;
if (files->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(files->data, (nLength+50)*sizeof(char *));
files->data = newPtr;
}
files->data[lf] =  file->d_name;
files->length = nLength+1;
} else {
files->data[lf] =  file->d_name;
};
};
file =  readdir(d);
};
closedir(d);
return files;
};
long int fileExists(char * path){
long int is =  access(path,0);
if ((is==0)) {
return 1;
}
return 0;
};
int removeFile(char * name){
if ((remove(name)==0)) {
return true;
}
return false;
};
#include <time.h>
struct time {
long int timestamp;
void(*now)(struct time* this);
char *(*format)(struct time* this,char * a);
long int(*since)(struct time* this);
};
void time__now(struct time* this){
this->timestamp =  time(0);
};
char * time__format(struct time* this,char * a){
long int lt =  localtime(&this->timestamp);
char * date =  memoryAlloc(1024);
strftime(date,1024,a,lt);
return date;
};
long int time__since(struct time* this){
long int nt =  time(0);
long int r =  nt - this->timestamp;
return r;
};
long int getTimeUnix(){
struct timespec ts =  {};
timespec_get(&ts,noCheck( TIME_UTC ));
long int s =  ts.tv_sec * 1000000000 + ts.tv_nsec;
return s;
};
#include <GL/gl.h>
#include <GL/glut.h>
#define MOUSE_LEFT_BUTTON 0
#define MOUSE_WHEEL_BUTTON 1
#define MOUSE_RIGHT_BUTTON 2
struct vec {
double x;
double y;
double x2;
double y2;
int simple;
struct vec(*mult)(struct vec* this,struct vec v2);
void(*set)(struct vec* this,struct vec v);
};
struct vec vec__mult(struct vec* this,struct vec v2){
struct vec r =  {};
r.simple = true;
r.mult = vec__mult;
if (((this->simple==true)&&(v2.simple==false))) {
r.x =  this->x * v2.x;
r.y =  this->x * v2.y;
r.x2 =  this->y * v2.x2;
r.y2 =  this->y * v2.y2;
r.x =  r.x + r.x2;
r.y =  r.y + r.y2;
r.x2 =  0.0;
r.y2 =  0.0;
}
else if (((this->simple==false)&&(v2.simple==true))) {
r.x =  this->x * v2.x;
r.y =  this->y * v2.x;
r.x2 =  this->x2 * v2.y;
r.y2 =  this->y2 * v2.y;
r.x =  r.x + r.x2;
r.y =  r.y + r.y2;
r.x2 =  0.0;
r.y2 =  0.0;
}
return r;
};
void vec__set(struct vec* this,struct vec v){
this->x =  v.x;
this->y =  v.y;
this->x2 =  v.x2;
this->x2 =  v.y2;
this->simple =  v.simple;
};
struct vec vec(double x,double y){
struct vec v =  {};
v.simple = true;
v.mult = vec__mult;
v.set = vec__set;
v.x =  x;
v.y =  y;
return v;
};
struct vec vec4(double x1,double y1,double x2,double y2){
struct vec v =  {};
v.simple = true;
v.mult = vec__mult;
v.set = vec__set;
v.x =  x1;
v.y =  y1;
v.x2 =  x2;
v.y2 =  y2;
v.simple =  false;
return v;
};
typedef array(double)* __BAH_ARR_TYPE_float;
void minCoords(struct vec* v,__BAH_ARR_TYPE_float shape){
if ((len(shape)<2)) {
return ;
}
v->x =  shape->data[0];
v->y =  shape->data[1];
long int i =  2;
while ((i<len(shape))) {
if ((shape->data[i]<v->x)) {
v->x =  shape->data[i];
}
if ((shape->data[i + 1]<v->y)) {
v->y =  shape->data[i + 1];
}
i =  i + 2;
};
};
void maxCoords(struct vec* v,__BAH_ARR_TYPE_float shape){
if ((len(shape)<2)) {
return ;
}
v->x =  shape->data[0];
v->y =  shape->data[1];
long int i =  2;
while ((i<len(shape))) {
if ((shape->data[i]>v->x)) {
v->x =  shape->data[i];
}
if ((shape->data[i + 1]>v->y)) {
v->y =  shape->data[i + 1];
}
i =  i + 2;
};
};
double dot(struct vec v1,struct vec v2){
return v1.x * v2.x + v1.y * v2.x;
};
void translateShape(struct vec v,__BAH_ARR_TYPE_float shape){
long int i =  0;
while ((i<len(shape))) {

{
long nLength = i;
if (shape->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(shape->data, (nLength+50)*sizeof(double));
shape->data = newPtr;
}
shape->data[i] =  shape->data[i] + v.x;
shape->length = nLength+1;
} else {
shape->data[i] =  shape->data[i] + v.x;
};
};

{
long nLength = i + 1;
if (shape->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(shape->data, (nLength+50)*sizeof(double));
shape->data = newPtr;
}
shape->data[i + 1] =  shape->data[i + 1] + v.y;
shape->length = nLength+1;
} else {
shape->data[i + 1] =  shape->data[i + 1] + v.y;
};
};
i =  i + 2;
};
};
void centerCoords(struct vec* v,__BAH_ARR_TYPE_float shape);
void circleFromShape(struct vec* v,double* rad,__BAH_ARR_TYPE_float shape){
centerCoords(v,shape);
struct vec min =  {};
min.simple = true;
min.mult = vec__mult;
min.set = vec__set;
minCoords(&min,shape);
struct vec max =  {};
max.simple = true;
max.mult = vec__mult;
max.set = vec__set;
maxCoords(&max,shape);
double radX =  v->x - min.x;
double radY =  v->y - min.y;
double minRad =  radX + radY / 2.0;
radX =  max.x - v->x;
radY =  max.y - v->y;
double maxRad =  radX + radY / 2.0;
if ((minRad>maxRad)) {
*rad =  minRad;
}
else {
*rad =  maxRad;
}
};
double degToRad(double d){
return d * 3.14159 / 180.0;
};
struct reflectElement {
long int size;
char * type;
char * name;
int isArray;
struct reflectElement* arrayElem;
int isStruct;
array(struct reflectElement)* structLayout;
long int offset;
void * value;
void *(*calculateOffset)(struct reflectElement* this,void * origin);
};
void * reflectElement__calculateOffset(struct reflectElement* this,void * origin){
char * base =  origin;
return noCheck( base + this->offset );
};
typedef array(struct reflectElement)* __BAH_ARR_TYPE_reflectElement;
struct reflectElement __reflect(void * v,long int s,char * t,char * n,int isArr,struct reflectElement* ae,int isStruct,__BAH_ARR_TYPE_reflectElement sl,long int offset){
struct reflectElement re =  {};
re.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            re.structLayout->length = 0;
            re.structLayout->elemSize = sizeof(struct reflectElement);
            re.calculateOffset = reflectElement__calculateOffset;
re.size =  s;
re.type =  t;
re.name =  n;
re.isArray =  isArr;
re.arrayElem =  ae;
re.isStruct =  isStruct;
re.structLayout =  sl;
re.value =  v;
re.offset =  offset;
return re;
};
#define JSON_TYPE_STRING 0
#define JSON_TYPE_INT 1
#define JSON_TYPE_FLOAT 2
#define JSON_TYPE_ARRAY 3
#define JSON_TYPE_MAP 4
char * toJson(struct reflectElement e);
struct jsonElement {
long int type;
char * key;
char * content;
array(struct jsonElement*)* children;
struct jsonElement*(*map)(struct jsonElement* this,char * key);
char *(*str)(struct jsonElement* this);
void(*scan)(struct jsonElement* this,struct reflectElement e);
};
struct jsonElement* jsonElement__map(struct jsonElement* this,char * key){
long int l =  len(this->children);
long int i =  0;
while ((i<l)) {
struct jsonElement* elem =  this->children->data[i];
char fc =  cpstringCharAt(elem->key,0);
if ((fc==(char)34)) {
array(char)* nk = memoryAlloc(sizeof(array(char)));

nk->length = 0;
nk->elemSize = sizeof(char);
long int lk =  strlen(elem->key);
long int j =  1;
while ((j<lk - 1)) {
char c =  cpstringCharAt(elem->key,j);

{
long nLength = j-1;
if (nk->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nk->data, (nLength+50)*sizeof(char));
nk->data = newPtr;
}
nk->data[j-1] =  c;
nk->length = nLength+1;
} else {
nk->data[j-1] =  c;
};
};
j =  j + 1;
};
if ((strcmp(arrAsStr(nk), key) == 0)) {
return elem;
}
}
else {
if ((strcmp(elem->key, key) == 0)) {
return elem;
}
}
i =  i + 1;
};
void * z =  (void *)0;
return z;
};
char * jsonElement__str(struct jsonElement* this){
char * ctn =  this->content;
return ctn;
};
void jsonElement__scan(struct jsonElement* this,struct reflectElement e){
if ((e.isStruct==true)) {
long int i =  0;
while ((i<len(e.structLayout))) {
struct reflectElement m =  e.structLayout->data[i];
struct jsonElement* ov =  this->map((struct jsonElement*)this,m.name);
if ((ov!=null)) {
ov->scan((struct jsonElement*)ov,m);
}
i =  i + 1;
};
}
else if ((strcmp(e.type, "int") == 0)) {
long int* ep =  e.value;
*ep =  strToInt(this->content);
}
else if ((strcmp(e.type, "cpstring") == 0)) {
char ** ep =  e.value;
*ep =  memoryAlloc(strlen(this->content));
strcpy(*ep,this->content);
}
else if ((strcmp(e.type, "float") == 0)) {
double* ep =  e.value;
*ep =  strToFloat(this->content);
}
else if ((strcmp(e.type, "bool") == 0)) {
int* ep =  e.value;
if (((strcmp(this->content, "1") == 0)||(strcmp(this->content, "true") == 0))) {
*ep =  true;
}
else {
*ep =  false;
}
}
else if ((e.isArray==true)) {
struct reflectElement* ae =  e.arrayElem;
if ((strcmp(ae->type, "int") == 0)) {
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(this->children))) {
struct jsonElement* c =  this->children->data[i];

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(arr->data, (nLength+50)*sizeof(long int));
arr->data = newPtr;
}
arr->data[i] =  strToInt(c->content);
arr->length = nLength+1;
} else {
arr->data[i] =  strToInt(c->content);
};
};
i =  i + 1;
};
}
else if ((strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(this->children))) {
struct jsonElement* c =  this->children->data[i];

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(arr->data, (nLength+50)*sizeof(double));
arr->data = newPtr;
}
arr->data[i] =  strToFloat(c->content);
arr->length = nLength+1;
} else {
arr->data[i] =  strToFloat(c->content);
};
};
i =  i + 1;
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(this->children))) {
struct jsonElement* c =  this->children->data[i];

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(arr->data, (nLength+50)*sizeof(char *));
arr->data = newPtr;
}
arr->data[i] =  memoryAlloc(strlen(c->content));
arr->length = nLength+1;
} else {
arr->data[i] =  memoryAlloc(strlen(c->content));
};
};
strcpy(arr->data[i],c->content);
i =  i + 1;
};
}
else if ((ae->isStruct==true)) {
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);
arr =  e.value;
long int i =  0;
while ((i<len(this->children))) {
struct jsonElement* c =  this->children->data[i];
void * ne =  memoryAlloc(ae->size);
long int j =  0;
while ((j<len(ae->structLayout))) {
struct reflectElement m =  ae->structLayout->data[j];
m.value =  m.calculateOffset((struct reflectElement*)&m,ne);
struct jsonElement* ov =  c->map((struct jsonElement*)c,m.name);
if ((ov!=null)) {
ov->scan((struct jsonElement*)ov,m);
}
j =  j + 1;
};

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(arr->data, (nLength+50)*sizeof(void *));
arr->data = newPtr;
}
arr->data[i] =  ne;
arr->length = nLength+1;
} else {
arr->data[i] =  ne;
};
};
i =  i + 1;
};
}
}
};
struct jsonElement* parseJson(char * s){
struct jsonElement* jsonElem = memoryAlloc(sizeof(struct jsonElement));
jsonElem->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            jsonElem->children->length = 0;
            jsonElem->children->elemSize = sizeof(struct jsonElement*);
            jsonElem->map = jsonElement__map;
jsonElem->str = jsonElement__str;
jsonElem->scan = jsonElement__scan;
long int lenS =  strlen(s);
long int i =  0;
while ((i<lenS)) {
if ((isSpace(cpstringCharAt(s,i))==0)) {
break;
}
i =  i + 1;
};
char fc =  cpstringCharAt(s,i);
if ((fc==91)) {
jsonElem->type =  JSON_TYPE_ARRAY;
}
else if ((fc==123)) {
jsonElem->type =  JSON_TYPE_MAP;
}
else if ((fc==(char)34)) {
jsonElem->type =  JSON_TYPE_STRING;
array(char)* ns = memoryAlloc(sizeof(array(char)));

ns->length = 0;
ns->elemSize = sizeof(char);
i =  i + 1;
while ((i<lenS - 1)) {

{
long nLength = len(ns);
if (ns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(ns->data, (nLength+50)*sizeof(char));
ns->data = newPtr;
}
ns->data[len(ns)] =  cpstringCharAt(s,i);
ns->length = nLength+1;
} else {
ns->data[len(ns)] =  cpstringCharAt(s,i);
};
};
i =  i + 1;
};
jsonElem->content =  arrToStr(ns);
}
else if (isNumber(fc)) {
int isFloat =  false;
while ((i<lenS)) {
if ((cpstringCharAt(s,i)==46)) {
isFloat =  true;
break;
}
i =  i + 1;
};
if ((isFloat==true)) {
jsonElem->type =  JSON_TYPE_FLOAT;
}
else {
jsonElem->type =  JSON_TYPE_INT;
}
jsonElem->content =  s;
}
else {
jsonElem->type =  JSON_TYPE_STRING;
jsonElem->content =  s;
}
if ((jsonElem->type==JSON_TYPE_ARRAY)) {
i =  i + 1;
long int trim =  1;
long int j =  lenS-1;
while ((j>=0)) {
char c =  cpstringCharAt(s,j);
if (isSpace(c)) {
trim =  trim + 1;
}
else {
break;
}
j =  j - 1;
};
while ((i<lenS - 1)) {
char c =  cpstringCharAt(s,i);
if ((isSpace(c)==0)) {
break;
}
i =  i + 1;
};
array(char)* currentElem = memoryAlloc(sizeof(array(char)));

currentElem->length = 0;
currentElem->elemSize = sizeof(char);
long int currentBracks =  0;
long int currentBraces =  0;
long int currentQuotes =  0;
long int elemIndex =  0;
while ((i<lenS - trim)) {
char c =  cpstringCharAt(s,i);
if ((c==(char)34)) {
if ((currentQuotes==0)) {
currentQuotes =  1;
}
else {
currentQuotes =  0;
}
}
else if ((c==91)) {
currentBracks =  currentBracks + 1;
}
else if ((c==93)) {
currentBracks =  currentBracks - 1;
}
else if ((c==123)) {
currentBraces =  currentBraces + 1;
}
else if ((c==125)) {
currentBraces =  currentBraces - 1;
}
long int total =  currentBracks + currentBraces + currentQuotes;
if ((total>0)) {

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
};
};
i =  i + 1;
continue;
}
if ((c==44)) {

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  parseJson(arrToStr(currentElem));
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  parseJson(arrToStr(currentElem));
};
};
clear(currentElem);
elemIndex =  elemIndex + 1;
}
else {
if (isSpace(c)) {
i =  i + 1;
continue;
}

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
};
};
}
i =  i + 1;
};

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  parseJson(arrToStr(currentElem));
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  parseJson(arrToStr(currentElem));
};
};
}
else if ((jsonElem->type==JSON_TYPE_MAP)) {
i =  i + 1;
long int trim =  1;
long int j =  lenS-1;
while ((j>=0)) {
char c =  cpstringCharAt(s,j);
if (isSpace(c)) {
trim =  trim + 1;
}
else {
break;
}
j =  j - 1;
};
while ((i<lenS - 1)) {
char c =  cpstringCharAt(s,i);
if ((isSpace(c)==0)) {
break;
}
i =  i + 1;
};
array(char)* currentElem = memoryAlloc(sizeof(array(char)));

currentElem->length = 0;
currentElem->elemSize = sizeof(char);
array(char)* currentKey = memoryAlloc(sizeof(array(char)));

currentKey->length = 0;
currentKey->elemSize = sizeof(char);
long int isVal =  0;
long int currentBracks =  0;
long int currentBraces =  0;
long int currentQuotes =  0;
long int elemIndex =  0;
while ((i<lenS - trim)) {
char c =  cpstringCharAt(s,i);
if ((c==(char)34)) {
if ((currentQuotes==0)) {
currentQuotes =  1;
}
else {
currentQuotes =  0;
}
}
else if ((c==91)) {
currentBracks =  currentBracks + 1;
}
else if ((c==93)) {
currentBracks =  currentBracks - 1;
}
else if ((c==123)) {
currentBraces =  currentBraces + 1;
}
else if ((c==125)) {
currentBraces =  currentBraces - 1;
}
long int total =  currentBracks + currentBraces + currentQuotes;
if ((total>0)) {
if ((isVal==1)) {

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
};
};
}
else {

{
long nLength = len(currentKey);
if (currentKey->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(currentKey->data, (nLength+50)*sizeof(char));
currentKey->data = newPtr;
}
currentKey->data[len(currentKey)] =  c;
currentKey->length = nLength+1;
} else {
currentKey->data[len(currentKey)] =  c;
};
};
}
i =  i + 1;
continue;
}
if ((c==58)) {
isVal =  1;
}
else if ((c==44)) {
struct jsonElement* elem =  parseJson(arrToStr(currentElem));
elem->key =  arrToStr(currentKey);
clear(currentElem);
clear(currentKey);
isVal =  0;

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  elem;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  elem;
};
};
elemIndex =  elemIndex + 1;
}
else {
if (isSpace(c)) {
i =  i + 1;
continue;
}
if ((isVal==1)) {

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
};
};
}
else {

{
long nLength = len(currentKey);
if (currentKey->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(currentKey->data, (nLength+50)*sizeof(char));
currentKey->data = newPtr;
}
currentKey->data[len(currentKey)] =  c;
currentKey->length = nLength+1;
} else {
currentKey->data[len(currentKey)] =  c;
};
};
}
}
i =  i + 1;
};
struct jsonElement* elem =  parseJson(arrToStr(currentElem));
elem->key =  arrToStr(currentKey);

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  elem;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  elem;
};
};
}
return jsonElem;
};
char * toJson__inner(struct reflectElement e,int isMember,long int tabs){
void ** v =  e.value;
if ((*v==null)) {
return "null";
}
if ((e.isStruct==true)) {
tabs =  tabs + 1;
char * tabsStr =  "";
long int i =  0;
while ((i<tabs)) {
tabsStr =  concatCPSTRING(tabsStr,"\t");
i =  i + 1;
};
char * s =  "{\n";
i =  0;
while ((i<len(e.structLayout))) {
struct reflectElement m =  e.structLayout->data[i];
i =  i + 1;
if ((i<len(e.structLayout))) {

                        char* ____BAH_COMPILER_VAR_0; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("\"");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\": ");
long int strLen_5 = strlen(toJson__inner(m,true,tabs));
long int strLen_6 = strlen(",\n");
;                            
                            ____BAH_COMPILER_VAR_0 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                            
                            strncpy(____BAH_COMPILER_VAR_0+currStrOff, s, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_0+currStrOff, tabsStr, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_0+currStrOff, "\"", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_0+currStrOff, m.name, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_0+currStrOff, "\": ", strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_0+currStrOff, toJson__inner(m,true,tabs), strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_0+currStrOff, ",\n", strLen_6);
                            currStrOff += strLen_6;
                            
                        }
                        s =  ____BAH_COMPILER_VAR_0;
}
else {

                        char* ____BAH_COMPILER_VAR_1; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("\"");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\": ");
long int strLen_5 = strlen(toJson__inner(m,true,tabs));
long int strLen_6 = strlen("\n");
;                            
                            ____BAH_COMPILER_VAR_1 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                            
                            strncpy(____BAH_COMPILER_VAR_1+currStrOff, s, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_1+currStrOff, tabsStr, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_1+currStrOff, "\"", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_1+currStrOff, m.name, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_1+currStrOff, "\": ", strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_1+currStrOff, toJson__inner(m,true,tabs), strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_1+currStrOff, "\n", strLen_6);
                            currStrOff += strLen_6;
                            
                        }
                        s =  ____BAH_COMPILER_VAR_1;
}
};
tabs =  tabs - 1;
tabsStr =  "";
i =  0;
while ((i<tabs)) {
tabsStr =  concatCPSTRING(tabsStr,"\t");
i =  i + 1;
};

                        char* ____BAH_COMPILER_VAR_2; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("}");
;                            
                            ____BAH_COMPILER_VAR_2 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_2+currStrOff, s, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_2+currStrOff, tabsStr, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_2+currStrOff, "}", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        s =  ____BAH_COMPILER_VAR_2;
return s;
}
else if ((strcmp(e.type, "int") == 0)) {
long int* ip =  e.value;
return intToStr(*ip);
}
else if ((strcmp(e.type, "float") == 0)) {
double* fp =  e.value;
return floatToStr(*fp);
}
else if ((strcmp(e.type, "cpstring") == 0)) {
if ((isMember==false)) {
struct string s =  string(e.value);
s.replace((struct string*)&s,"\"","\\\"");
s.replace((struct string*)&s,"\n","\\\n");

                        char* ____BAH_COMPILER_VAR_3; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(s.str((struct string*)&s));
long int strLen_2 = strlen("\"");
;                            
                            ____BAH_COMPILER_VAR_3 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_3+currStrOff, "\"", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_3+currStrOff, s.str((struct string*)&s), strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_3+currStrOff, "\"", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        return ____BAH_COMPILER_VAR_3;
}
else {
char ** sp =  e.value;
struct string s =  string(*sp);
s.replace((struct string*)&s,"\"","\\\"");
s.replace((struct string*)&s,"\n","\\\n");

                        char* ____BAH_COMPILER_VAR_4; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(s.str((struct string*)&s));
long int strLen_2 = strlen("\"");
;                            
                            ____BAH_COMPILER_VAR_4 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_4+currStrOff, "\"", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_4+currStrOff, s.str((struct string*)&s), strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_4+currStrOff, "\"", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        return ____BAH_COMPILER_VAR_4;
}
}
else if ((e.isArray==true)) {
char * s =  "[";
struct reflectElement* ae =  e.arrayElem;
if ((strcmp(ae->type, "int") == 0)) {
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(arr))) {
s =  concatCPSTRING(s,intToStr(arr->data[i]));
i =  i + 1;
if ((i<len(arr))) {
s =  concatCPSTRING(s,",");
}
};
}
else if ((strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(arr))) {
s =  concatCPSTRING(s,floatToStr(arr->data[i]));
i =  i + 1;
if ((i<len(arr))) {
s =  concatCPSTRING(s,",");
}
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr =  e.value;
arr =  *arrPtr;
s =  concatCPSTRING(s,"\n");
long int i =  0;
while ((i<len(arr))) {
s =  concatCPSTRING(s,arr->data[i]);
i =  i + 1;
if ((i<len(arr))) {
s =  concatCPSTRING(s,",\n");
}
else {
s =  concatCPSTRING(s,"\n");
}
};
}
else if ((ae->isStruct==true)) {
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);
arr =  e.value;
long int i =  0;
while ((i<len(arr))) {
void * arrElem =  arr->data[i];
ae->value =  arrElem;
long int j =  0;
while ((j<len(ae->structLayout))) {
struct reflectElement m =  ae->structLayout->data[j];
m.value =  m.calculateOffset((struct reflectElement*)&m,ae->value);

{
long nLength = j;
if (ae->structLayout->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(ae->structLayout->data, (nLength+50)*sizeof(struct reflectElement));
ae->structLayout->data = newPtr;
}
ae->structLayout->data[j] =  m;
ae->structLayout->length = nLength+1;
} else {
ae->structLayout->data[j] =  m;
};
};
j =  j + 1;
};
s =  concatCPSTRING(s,toJson__inner(*ae,false,tabs));
i =  i + 1;
if ((i<len(arr))) {
s =  concatCPSTRING(s,",\n");
}
else {
s =  concatCPSTRING(s,"\n");
}
};
}
s =  concatCPSTRING(s,"]");
return s;
}
return "";
};
char * toJson(struct reflectElement e){
return toJson__inner(e,false,0);
};
void rotateShape(double rot,__BAH_ARR_TYPE_float shape){
rot =  degToRad(rot);
struct vec mat =  vec4(cos(rot),-1.0 * sin(rot),sin(rot),cos(rot));
struct vec nx =  {};
nx.simple = true;
nx.mult = vec__mult;
nx.set = vec__set;
struct vec ny =  {};
ny.simple = true;
ny.mult = vec__mult;
ny.set = vec__set;
long int i =  0;
while ((i<len(shape))) {
struct vec s =  vec(shape->data[i],shape->data[i + 1]);

        array(struct reflectElement) * ____BAH_COMPILER_VAR_5 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_5->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_5->length = 5;
        ____BAH_COMPILER_VAR_5->data = memoryAlloc(____BAH_COMPILER_VAR_5->length * ____BAH_COMPILER_VAR_5->elemSize);
        ____BAH_COMPILER_VAR_5->data[0] = __reflect((double*)((char*)(&s) + offsetof(struct vec, x)), sizeof(double), "float", "x", 0, 0, 0, 0, offsetof(struct vec, x));
____BAH_COMPILER_VAR_5->data[1] = __reflect((double*)((char*)(&s) + offsetof(struct vec, y)), sizeof(double), "float", "y", 0, 0, 0, 0, offsetof(struct vec, y));
____BAH_COMPILER_VAR_5->data[2] = __reflect((double*)((char*)(&s) + offsetof(struct vec, x2)), sizeof(double), "float", "x2", 0, 0, 0, 0, offsetof(struct vec, x2));
____BAH_COMPILER_VAR_5->data[3] = __reflect((double*)((char*)(&s) + offsetof(struct vec, y2)), sizeof(double), "float", "y2", 0, 0, 0, 0, offsetof(struct vec, y2));
____BAH_COMPILER_VAR_5->data[4] = __reflect((int*)((char*)(&s) + offsetof(struct vec, simple)), sizeof(int), "bool", "simple", 0, 0, 0, 0, offsetof(struct vec, simple));
println(toJson(__reflect(&s, sizeof(struct vec*), "vec*", "&s", 0, 0, 1, ____BAH_COMPILER_VAR_5, 0)));
struct vec rs =  mat.mult(&mat, s);

{
long nLength = i;
if (shape->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(shape->data, (nLength+50)*sizeof(double));
shape->data = newPtr;
}
shape->data[i] =  rs.x;
shape->length = nLength+1;
} else {
shape->data[i] =  rs.x;
};
};

{
long nLength = i + 1;
if (shape->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(shape->data, (nLength+50)*sizeof(double));
shape->data = newPtr;
}
shape->data[i + 1] =  rs.y;
shape->length = nLength+1;
} else {
shape->data[i + 1] =  rs.y;
};
};
i =  i + 2;
};
};
int detectCollideCircle(struct vec v1,double rad1,struct vec v2,double rad2){
struct vec dist =  vec(v1.x - v2.x,v1.y - v2.y);
double sumRad =  rad1 + rad2;
if ((dist.x * dist.x + dist.y * dist.y<=sumRad * sumRad)) {
return true;
}
return false;
};
GLuint BMPtoTex(char * path,long int w,long int h){
GLuint texture;
struct fileStream fs =  {};
fs.isValid = fileStream__isValid;
fs.open = fileStream__open;
fs.close = fileStream__close;
fs.getPos = fileStream__getPos;
fs.setPos = fileStream__setPos;
fs.getSize = fileStream__getSize;
fs.rewind = fileStream__rewind;
fs.getChar = fileStream__getChar;
fs.setChar = fileStream__setChar;
fs.createFile = fileStream__createFile;
fs.writeFile = fileStream__writeFile;
fs.writePtr = fileStream__writePtr;
fs.readPtr = fileStream__readPtr;
fs.readContent = fileStream__readContent;
fs.readBytes = fileStream__readBytes;
fs.writeBytes = fileStream__writeBytes;
fs.open((struct fileStream*)&fs,path,"rb");
fs.setPos((struct fileStream*)&fs,54);
if ((fs.isValid((struct fileStream*)&fs)==0)) {
return null;
}
array(char)* data =  fs.readBytes((struct fileStream*)&fs);
fs.close((struct fileStream*)&fs);
long int i =  0;
while ((i<w * h)) {
long int index =  i * 3;
char b =  data->data[index];
char r =  data->data[index + 2];

{
long nLength = index;
if (data->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(data->data, (nLength+50)*sizeof(char));
data->data = newPtr;
}
data->data[index] =  r;
data->length = nLength+1;
} else {
data->data[index] =  r;
};
};

{
long nLength = index + 2;
if (data->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(data->data, (nLength+50)*sizeof(char));
data->data = newPtr;
}
data->data[index + 2] =  b;
data->length = nLength+1;
} else {
data->data[index + 2] =  b;
};
};
i =  i + 1;
};
glGenTextures(1,&texture);
glBindTexture(noCheck( GL_TEXTURE_2D ),texture);
glTexEnvf(noCheck( GL_TEXTURE_ENV ),noCheck( GL_TEXTURE_ENV_MODE ),noCheck( GL_MODULATE ));
glTexParameterf(noCheck( GL_TEXTURE_2D ),noCheck( GL_TEXTURE_MIN_FILTER ),noCheck( GL_LINEAR_MIPMAP_NEAREST ));
glTexParameterf(noCheck( GL_TEXTURE_2D ),noCheck( GL_TEXTURE_MAG_FILTER ),noCheck( GL_LINEAR ));
glTexParameterf(noCheck( GL_TEXTURE_2D ),noCheck( GL_TEXTURE_WRAP_S ),noCheck( GL_REPEAT ));
glTexParameterf(noCheck( GL_TEXTURE_2D ),noCheck( GL_TEXTURE_WRAP_T ),noCheck( GL_REPEAT ));
gluBuild2DMipmaps(noCheck( GL_TEXTURE_2D ),3,w,h,noCheck( GL_RGB ),noCheck( GL_UNSIGNED_BYTE ),arrAsStr(data));
return texture;
};
struct rgb {
double r;
double g;
double b;
int isTex;
GLuint tex;
long int texW;
long int texH;
};
struct rgb rgb(double r,double g,double b){
struct rgb rgb =  {};
rgb.isTex = false;
rgb.r =  r;
rgb.g =  g;
rgb.b =  b;
return rgb;
};
struct rgb rgbTexture(char * path,long int w,long int h){
struct rgb c =  {};
c.isTex = false;
c.isTex =  true;
c.tex =  BMPtoTex(path,w,h);
c.texW =  w;
c.texH =  h;
return c;
};
int setDrawingColor(struct rgb color){
if ((color.isTex==false)) {
glColor3f(color.r,color.g,color.b);
}
else {
glColor3f(1.0,1.0,1.0);
glBindTexture(noCheck( GL_TEXTURE_2D ),color.tex);
glEnable(noCheck( GL_TEXTURE_2D ));
}
return color.isTex;
};
void drawCircle(struct vec v,double radius,struct rgb color){
setDrawingColor(color);
glBegin(noCheck( GL_TRIANGLE_FAN ));
double texX =  0.5;
double texY =  0.5;
glTexCoord2f(texX,texY);
glVertex2f(v.x,v.y);
double twicePi =  2.0 * 3.142;
long int res =  radius * 30.0;
if ((res<20)) {
res =  20;
}
long int i =  0;
while ((i<=res)) {
double xr =  radius * cos((double)i * twicePi / (double)res);
double yr =  radius * sin((double)i * twicePi / (double)res);
glTexCoord2f(texX + xr,texY + yr);
glVertex2f(v.x + xr,v.y + yr);
i =  i + 1;
};
glEnd();
glDisable(noCheck( GL_TEXTURE_2D ));
};
void drawBox(struct vec v,double w,double h,struct rgb color){
int isTex =  setDrawingColor(color);
glBegin(noCheck( GL_TRIANGLE_FAN ));
double hw =  w / 2.0;
double hh =  h / 2.0;
glTexCoord2f(0.0,1.0);
glVertex2f(v.x - hw,v.y + hh);
glTexCoord2f(1.0,1.0);
glVertex2f(v.x + hw,v.y + hh);
glTexCoord2f(1.0,0.0);
glVertex2f(v.x + hw,v.y - hh);
glTexCoord2f(0.0,0.0);
glVertex2f(v.x - hw,v.y - hh);
glEnd();
glDisable(noCheck( GL_TEXTURE_2D ));
};
void drawShape(__BAH_ARR_TYPE_float shape,struct rgb color){
if ((len(shape)==0)) {
return ;
}
int isTex =  setDrawingColor(color);
glBegin(noCheck( GL_TRIANGLE_FAN ));
struct vec c =  {};
c.simple = true;
c.mult = vec__mult;
c.set = vec__set;
centerCoords(&c,shape);
long int i =  0;
while ((i<len(shape))) {
glTexCoord2f(shape->data[i] - c.x + 0.5,shape->data[i + 1] - c.y + 0.5);
glVertex2f(shape->data[i],shape->data[i + 1]);
i =  i + 2;
};
glEnd();
glDisable(noCheck( GL_TEXTURE_2D ));
};
void drawText(struct vec v,struct rgb color,void * font,char * str){
glColor3f(color.r,color.g,color.b);
glRasterPos2f(v.x,v.y);
glutBitmapString(font,str);
};
void centerCoords(struct vec* v,__BAH_ARR_TYPE_float shape){
struct vec tmp =  {};
tmp.simple = true;
tmp.mult = vec__mult;
tmp.set = vec__set;
long int i =  0;
while ((i<len(shape))) {
tmp.x =  tmp.x + shape->data[i];
tmp.y =  tmp.y + shape->data[i + 1];
i =  i + 2;
};
long int div =  i / 2;
v->x =  tmp.x / (double)div;
v->y =  tmp.y / (double)div;
};
void clearFrame(){
glClearColor(0.0,0.0,0.0,1.0);
glClear(noCheck( GL_COLOR_BUFFER_BIT ));
};
void redrawFrame(){
glutPostRedisplay();
};
void sendFrame(){
glutSwapBuffers();
};
void __VBAH_display();
void __VBAH_idle();
void __VBAH_mouse(long int btn,long int state,long int x,long int y);
void __VBAH_move(long int x,long int y);
void __VBAH_drag(long int x,long int y);
void __VBAH_keyboard(char key,long int x,long int y);
void __VBAH_resize(long int w,long int h);
struct window {
long int width;
long int height;
long int x;
long int y;
char * title;
int autoClear;
int autoLoop;
double lb;
double tb;
double rb;
double bb;
void (*display)();
void (*idle)();
void (*init)();
void (*click)(long int,int,long int,long int);
void (*move)(long int,long int);
void (*drag)(long int,long int);
void (*keyboard)(char,long int,long int);
double delta;
double lastTimeDelta;
void(*launch)(struct window* this);
void(*endDelta)(struct window* this);
long int(*fps)(struct window* this);
long int oldW;
long int oldH;
int fullscreened;
void(*fullscreen)(struct window* this);
double(*getWidth)(struct window* this);
double(*getHeight)(struct window* this);
};
void window__launch(struct window* this){
glutInitWindowSize(this->width,this->height);
glutInitWindowPosition(this->x,this->y);
glutCreateWindow(this->title);
glutDisplayFunc(__VBAH_display);
glutIdleFunc(__VBAH_idle);
glutMouseFunc(__VBAH_mouse);
glutPassiveMotionFunc(__VBAH_move);
glutMotionFunc(__VBAH_drag);
glutKeyboardFunc(__VBAH_keyboard);
glutReshapeFunc(__VBAH_resize);
void (*init)() =  this->init;
if ((init!=null)) {
init();
}
this->lastTimeDelta =  (double)getTimeUnix();
glutMainLoop();
};
void window__endDelta(struct window* this){
double nltd =  getTimeUnix();
double delta =  nltd - this->lastTimeDelta;
this->lastTimeDelta =  nltd;
delta =  delta / 1000000000.0;
this->delta =  delta;
};
long int window__fps(struct window* this){
double fps =  1.0 / this->delta;
return (long int)fps;
};
void window__fullscreen(struct window* this){
if ((this->fullscreened==false)) {
this->oldW =  this->width;
this->oldH =  this->height;
glutFullScreen();
this->fullscreened =  true;
}
else {
glutReshapeWindow(this->oldW,this->oldH);
this->fullscreened =  false;
}
};
double window__getWidth(struct window* this){
return (double)glutGet(noCheck( GLUT_WINDOW_WIDTH ));
};
double window__getHeight(struct window* this){
return (double)glutGet(noCheck( GLUT_WINDOW_HEIGHT ));
};
struct window* WINDOW_PTR;
void __VBAH_display(){
if ((WINDOW_PTR->autoClear==true)) {
clearFrame();
}
void (*dsp)() =  WINDOW_PTR->display;
if ((dsp!=null)) {
dsp();
sendFrame();
}
WINDOW_PTR->endDelta((struct window*)WINDOW_PTR);
};
void __VBAH_idle(){
void (*idl)() =  WINDOW_PTR->display;
if ((idl!=null)) {
idl();
}
if ((WINDOW_PTR->autoLoop==true)) {
redrawFrame();
}
};
void __VBAH_mouse(long int btn,long int state,long int x,long int y){
void (*mse)(long int,int,long int,long int) =  WINDOW_PTR->click;
if ((mse!=null)) {
int clicked =  false;
if ((state==0)) {
clicked =  true;
}
mse(btn,clicked,x,y);
}
};
void __VBAH_move(long int x,long int y){
void (*mve)(long int,long int) =  WINDOW_PTR->move;
if ((mve!=null)) {
mve(x,y);
}
};
void __VBAH_drag(long int x,long int y){
void (*mve)(long int,long int) =  WINDOW_PTR->drag;
if ((mve!=null)) {
mve(x,y);
}
};
void __VBAH_keyboard(char key,long int x,long int y){
void (*kb)(char,long int,long int) =  WINDOW_PTR->keyboard;
if ((kb!=null)) {
kb(key,x,y);
}
};
void pixelsToCoords(struct vec* v);
void __VBAH_resize(long int w,long int h){
double ar =  (double)h / (double)w;
WINDOW_PTR->width =  w;
WINDOW_PTR->height =  h;
glViewport(0,0,w,h);
glMatrixMode(noCheck( GL_PROJECTION ));
glLoadIdentity();
if ((w>=h)) {
gluOrtho2D(-1.0 / ar,1.0 / ar,-1.0,1.0);
WINDOW_PTR->lb =  -1.0 / ar;
WINDOW_PTR->rb =  1.0 / ar;
WINDOW_PTR->tb =  1.0;
WINDOW_PTR->bb =  -1.0;
}
else {
gluOrtho2D(-1.0,1.0,-1.0 * ar,1.0 * ar);
WINDOW_PTR->lb =  -1.0;
WINDOW_PTR->rb =  1.0;
WINDOW_PTR->bb =  -1.0 * ar;
WINDOW_PTR->tb =  1.0 * ar;
}
glMatrixMode(noCheck( GL_MODELVIEW ));
};
void pixelsToCoords(struct vec* v){
double* m =  memoryAlloc(SIZE_OF_FLOAT * 16);
double* p =  memoryAlloc(SIZE_OF_FLOAT * 16);
long int* vp =  memoryAlloc(SIZE_OF_INT * 4);
glGetDoublev(noCheck( GL_MODELVIEW_MATRIX ),m);
glGetIntegerv(noCheck( GL_VIEWPORT ),vp);
glGetDoublev(noCheck( GL_PROJECTION_MATRIX ),p);
double nx;
double ny;
double nz;
gluUnProject(v->x,v->y,0.0,m,p,vp,&nx,&ny,&nz);
v->x =  nx;
v->y =  ny * -1.0;
};
struct window* window(long int w,long int h,char * t){
struct window* win = memoryAlloc(sizeof(struct window));
win->autoClear = true;
win->autoLoop = true;
win->lb = -1.0;
win->tb = 1.0;
win->rb = 1.0;
win->bb = -1.0;
win->fullscreened = false;
win->launch = window__launch;
win->endDelta = window__endDelta;
win->fps = window__fps;
win->fullscreen = window__fullscreen;
win->getWidth = window__getWidth;
win->getHeight = window__getHeight;
win->width =  w;
win->height =  h;
win->title =  t;
win->x =  100;
win->y =  100;
long int argc =  0;
glutInit(&argc,null);
glutInitDisplayMode(noCheck( GLUT_DOUBLE | GLUT_RGB ));
WINDOW_PTR =  win;
return win;
};
struct window* win;
struct rgb tex;
struct userShape {
array(double)* shape;
struct rgb tex;
void(*draw)(struct userShape* this);
void(*drawPoints)(struct userShape* this);
};
void userShape__draw(struct userShape* this){
drawShape(this->shape,this->tex);
};
void userShape__drawPoints(struct userShape* this){
long int i =  0;
while ((i<len(this->shape))) {
drawCircle(vec(this->shape->data[i],this->shape->data[i + 1]),0.02,rgb(1.0,0.0,0.0));
i =  i + 2;
};
};
struct userShape shape;
void display(){
array(double)* triangle = memoryAlloc(sizeof(array(double)));

triangle->length = 6;
triangle->elemSize = sizeof(double);
triangle->data = memoryAlloc(sizeof(double) * 50);triangle->data[0] = -0.5;
triangle->data[1] = 0.0;
triangle->data[2] = 0.0;
triangle->data[3] = 0.5;
triangle->data[4] = 0.5;
triangle->data[5] = 0.0;
rotateShape(10.0 * win->delta,triangle);
drawShape(triangle,tex);
shape.draw((struct userShape*)&shape);
shape.drawPoints((struct userShape*)&shape);
};
void init(){
tex =  rgbTexture("./assets/tex.bmp",1920,1229);
{};
shape.shape = memoryAlloc(sizeof(array(double)));
            shape.shape->length = 0;
            shape.shape->elemSize = sizeof(double);
            shape.draw = userShape__draw;
shape.drawPoints = userShape__drawPoints;
shape.tex =  tex;
};
void click(long int btn,int pressed,long int x,long int y){
if ((pressed==true)) {
struct vec f =  vec((double)x,(double)y);
pixelsToCoords(&f);

{
long nLength = len(shape.shape);
if (shape.shape->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(shape.shape->data, (nLength+50)*sizeof(double));
shape.shape->data = newPtr;
}
shape.shape->data[len(shape.shape)] =  f.x;
shape.shape->length = nLength+1;
} else {
shape.shape->data[len(shape.shape)] =  f.x;
};
};

{
long nLength = len(shape.shape);
if (shape.shape->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(shape.shape->data, (nLength+50)*sizeof(double));
shape.shape->data = newPtr;
}
shape.shape->data[len(shape.shape)] =  f.y;
shape.shape->length = nLength+1;
} else {
shape.shape->data[len(shape.shape)] =  f.y;
};
};
}
};
long int main(__BAH_ARR_TYPE_cpstring args){
win =  window(600,600,"Shape");
win->display =  display;
win->init =  init;
win->click =  click;
win->launch((struct window*)win);
return 0;
};
