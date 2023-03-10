package bgu.spl.net.api;

import bgu.spl.net.genericServers.interfaces.ConnectionHandler;

public interface MessagingProtocol<T> {
    
    /**
     * process the given message 
     * @param msg the received message
     * @return the response to send or null if no response is expected by the client
     */
    T process(ConnectionHandler<T> handler, T msg);
 
    /**
     * @return true if the connection should be terminated
     */
    boolean shouldTerminate();

    /**
     * called after the connection is terminated
     */
    void terminatedCallback(ConnectionHandler<T> handler);
 
}