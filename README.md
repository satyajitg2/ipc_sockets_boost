# ipc_sockets_boost
Simple Interprocess communication server using boost


README - ipc_server
    A sample interprocess communication server that accepts tcp clients and 
    provides message flow across clients asynchronously.
    # Can start multiple servers with multiple ports.
    # Each server accepts multiple clients
    # Each client can communicate either in same server or across different
      servers. Each client has a unique client ID.
    # To communicate to a client it needs to identify it with a client ID 
    # To send a message across client prompts use | 'pipe' separated by 
      messsage
       For eg. "client_id|Message to client" - "2|Hello world message."
    
    [Shell prompt]# ./ipc_server.exe  [port1] [port2] ...
    #./ipc_server.exe 2233



README - tcp_client
    # To send a message across client prompts use | 'pipe' separated by 
      messsage
       For eg. "client_id|Message to client" - "2|Hello world message."
    
    [Shell prompt]# ./tcp_client.exe [hostname] [port1]
    #./tcp_client.exe localhost 2233



Usage :

To start ipc_server : 
        #./ipc_server.exe 2233 3344

To start tcp_client :
        #./tcp_client.exe localhost 2233

To start another tcp_client:
        #./tcp_client.exe localhost 2233

To start another tcp_client:
        #./tcp_client.exe localhost 3344

Send message from client 1 -> 2:
        #2|Hello from client 1
