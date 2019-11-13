#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
void
parseStory (xmlDocPtr doc, xmlNodePtr cur) {

	xmlChar *key;
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"keyword"))) {
		    key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		    printf("keyword: %s\n", key);
		    xmlFree(key);
 	    }
	cur = cur->next;
	}
    return;
}

void findElement(xmlDocPtr pDoc, xmlNodePtr current){

    xmlChar *key;
    while(current!=NULL){
        if(!xmlStrcmp(current->name,(const xmlChar*)"slave")){
            key = xmlNodeListGetString(pDoc, current->xmlChildrenNode, 1);
        }
        current=current->next;
    }
}


int main() {

    xmlNodePtr current;
    xmlDocPtr pDoc = xmlParseFile("/home/jjc62351/work/BL11K/TR6/test.xml");
    xmlChar *key;
    xmlChar* xmlbuff;
    int buffersize;

    //Xpath example
	xmlChar *xpath = (xmlChar*) "//keyword";

    if(pDoc == NULL){
        printf("Didn't read\n");
    }

    current = xmlDocGetRootElement(pDoc);
    current = current->xmlChildrenNode;

    while(current!=NULL){
        if(!xmlStrcmp(current->name,(const xmlChar*)"control_set")){
            key = xmlNodeListGetString(pDoc, current->xmlChildrenNode, 1);
		    xmlNodeSetContent(current,(const xmlChar*)"1");
            key = xmlNodeListGetString(pDoc, current->xmlChildrenNode, 1);
            printf("value: %s\n", key);
        }
        current=current->next;
    }

    //Print xml
    xmlDocDumpFormatMemory(pDoc, &xmlbuff, &buffersize, 1);
    printf("%s", (char *) xmlbuff);

}