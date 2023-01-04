package bgu.spl.net.genericServers.interfaces;

import java.io.IOException;

public interface ChannelsManager<T> {
    
    /**
     * Subscribe a user to a channel.
     * if the channel does not exist, it will be created.
     * @param handler
     * @param subId
     * @param channel
     * @throws IOException if the user is already subscribed to the channel
     * or if the subscription id is already in use.
     */
    void subscribe(ConnectionHandler<T> handler, int subId, String channel) throws IOException;
    
    /**
     * Unsubscribe a user from a channel.
     * @param handler
     * @param subId
     * @throws IOException if the user is not subscribed to the channel or
     * if the subscription id is not in use.
     */
    void unsubscribe(ConnectionHandler<T> handler, int subId) throws IOException;
    
    /**
     * Send a message to a specific user.
     * @param handler
     * @param msg
     */
    void whisper(ConnectionHandler<T> handler, T msg);

    /**
     * Send a message to all users subscribed to a channel.
     * @param channel
     * @param msg
     */
    void broadcast(String channel, T msg);
}
