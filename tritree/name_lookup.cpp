#include "name_lookup.h"


NameLookup::NameLookup()
{
root=new graphT;
root->name ='#';
root->endshere=0;

}

bool NameLookup::insert(string name)
{
	addChar(name,root);
	return true;
}

void  NameLookup ::addChar(string name ,graphT * curr)
{
	if(name.size()<=0) { curr->endshere =1;}
	else if(name.size() > 0)
	{

		if(curr->nodemap.find(name[0])!= curr->nodemap.end())
		{
			addChar(name.substr(1),curr->nodemap[name[0]]);
		}else {
			graphT * check =new graphT ;
			check->name = name[0];
			check->endshere=0;
			curr->nodemap[name[0]]=check;
			addChar(name.substr(1),check);
		}
	
	}
}

void NameLookup::getNextChars(string subString, vector<char>* next)
{
    graphT * nodeToStrtFrm = getNode(subString,root);
	if(nodeToStrtFrm != NULL)
	{
	if(nodeToStrtFrm->endshere==1) next->push_back('\0');
	addCharToVec(nodeToStrtFrm, next);
	}
	
	
	
}
int NameLookup::getNumNamesStartingWith(string nameStarting)
{   
	 globalCalls =0;
	 graphT * nodeToStrtFrm = getNode(nameStarting,root);
	 
	 if(nodeToStrtFrm != NULL)
	 {
       printin("",nodeToStrtFrm);
	 }
	 
	     
	return globalCalls;
}

void NameLookup::printin(string sofar,graphT *curr)
{
	if(curr->nodemap.empty() && curr->endshere==1) { globalCalls++;}
	else {
          
		if(curr->endshere ==1){ globalCalls++;}
		for (map<char,graphT *>::iterator it=curr->nodemap.begin(); it!=curr->nodemap.end(); ++it)
		{
			printin(sofar+it->first,curr->nodemap[it->first]);
           
		}
	}
}


void NameLookup::getNamesStartingWith(string nameStarting, vector<string> * name_list)
{
	
	 graphT * nodeToStrtFrm = getNode(nameStarting,root);
	 
	 if(nodeToStrtFrm != NULL)
	 {
		listofNames(nameStarting,nodeToStrtFrm,name_list);
	 }
	
}

void NameLookup:: listofNames(string soFar,graphT * curr ,vector<string>* name_list)
{
	if(curr->nodemap.empty() && curr->endshere==1) { name_list->push_back(soFar);}
	else {
          
		if(curr->endshere ==1){  name_list->push_back(soFar);}
		for (map<char,graphT *>::iterator it=curr->nodemap.begin(); it!=curr->nodemap.end(); ++it)
		{
			listofNames(soFar+it->first,curr->nodemap[it->first],name_list);
           
		}
	}
}

bool NameLookup::erase(string to_erase)
{
	graphT * nodeToStrtFrm = getNode(to_erase,root);
	if(nodeToStrtFrm == NULL) return false;
	else 
	{
		//No longer an endpt
		nodeToStrtFrm->endshere=0;
		
	}
	return true;
}


NameLookup::graphT * NameLookup::getNode(string sofar,graphT *curr)
{
	if(sofar.size()<=0) return curr;
	else {
		
	
			if(curr->nodemap.find(sofar[0]) != curr->nodemap.end())
			{
				 graphT *  next      = curr->nodemap[sofar[0]];
				 next      = getNode(sofar.substr(1),next);
				 return next;
			}else {
				   return NULL;
			}
		
		
		 
		        
	}
	
}

void NameLookup::addCharToVec(graphT * curr,vector<char> * next)
{    
	if(! curr->nodemap.empty()) 
	{
        
		for (map<char,graphT *>::iterator it=curr->nodemap.begin(); it!=curr->nodemap.end(); ++it)
		{   
			graphT * nextNode =curr->nodemap[it->first];
			
			
			int flag=0;
			for(int i=0;i<next->size();i++)
			{
				if(next->at(i) ==nextNode->name)  flag=1;
			}
	           if(flag ==0)
			   {
				 next->push_back(nextNode->name);
			    }
			   
			   addCharToVec(nextNode, next);
		}
	}
}
//#endif
