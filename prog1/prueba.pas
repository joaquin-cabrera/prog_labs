function estanTodas( lista : ListaPalabras; vocabulario : TipoVocabulario) : boolean;.
var p:Listapalabras;    
begin
    q:=lista;
    while pertenecepalabra(q^.info,vocabulario) and (q<>nil) do
    begin
        if q^.sig<>nil then
            q:=q^.sig;
        else
            q:=nil;
    end;
    
estantodas:=pertenecepalabra(q^.info,vocabulario);

end;

  
        
