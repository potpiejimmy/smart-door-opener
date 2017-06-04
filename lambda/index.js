'use strict';
var Alexa = require('alexa-sdk');
var nodeFetch = require('node-fetch');
 
var BACKEND_URL = 'https://api.particle.io/v1/devices/';

exports.handler = function(event, context, callback){
    var alexa = Alexa.handler(event, context);
    alexa.registerHandlers(handlers);
    alexa.execute();
};

var handlers = {
    "LaunchRequest": function() {
        invokeBackend.call(this, BACKEND_URL+process.env.DEVICE_ID+"/buzz?access_token="+process.env.ACCESS_TOKEN, {method: 'POST'}).then(body => {
            if (body.return_value) {
                this.emit(':tell', "Haustür geöffnet.");
            } else {
                this.emit(':tell', "Das hat leider nicht geklappt.");
            }
        });
    },
};

function invokeBackend(url, options) {
    return nodeFetch(url, options)
        .then(res => res.json())
        .catch(err => {
            this.emit(':tellWithCard', "Fehler", "Weltraum-Fehler", "" + JSON.stringify(err));
        });
}
