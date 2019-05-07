/**
 * This file contains a Lamda function that toggles the heating 
 * and cooling systems that is based on the current temprature 
 * updates sent from the temp sensor.
 * 
 * @author Nathan Boas
 */

const AWS = require('aws-sdk');//Creates an instance of the aws-sdk object 

AWS.config.update({region: process.env.AWS_DEFAULT_REGION || AWS.config.region || "us-east-1"});//Tells the AWS object what region we are using

const DynamoDB = new AWS.DynamoDB();//Creates a new instance of DynamoDB to do CRUD operations with
let iotdata = new AWS.IotData({endpoint: 'a121dcgirqexb0-ats.iot.us-east-1.amazonaws.com'});//Declare AWS IoT Endpoint



/**
 * Main entry point of the Lamda function  
 * 
 * @param {{temp: (number|undefined)}=} event
 *      temp: this is the current temprature reading
 *            of the temp sensor.
 */
exports.handler = (event) => {

    let currentTemp = event.temp;

    console.log(currentTemp);

    try{
       updateDB(currentTemp);//update database with newly read ambient temprature
       getIdealTemp(currentTemp);//get the users ideal temprature to turn off/on temp regulation systems
    }catch(err){
        console.log(err);
    }
    
    return;
};


/**
 * This function updates a users current ambient temprature in tempData DynamoDB table 
 * 
 * @param {double} currentTemp this is the current temprature of the system
 * @return {null} this function
 */
function updateDB(currentTemp) {

    console.log('Updating Current Temprature');

    let updateParams = {
        TableName: 'tempData',
        Key: {
            "userID":{
                'S':'testDevice'
            }
        },
        UpdateExpression: "set currentTemp = :r",
        ExpressionAttributeValues: {
            ":r": {
                    "N": currentTemp.toString(10)
            },
           
        },
        ReturnValues:"UPDATED_NEW"
    };

    DynamoDB.updateItem(updateParams,function(err, data) {
        if (err) {
            console.error("Unable to update item. Error JSON:", JSON.stringify(err, null, 2));
        } else {
            console.log("UpdateItem succeeded:", JSON.stringify(data, null, 2));
        }
    });

    return;
}

/** * 
 * This function makes a call to the tempData DynamoDB table and retrieves the 
 * idealAmbient tempraturethen calls the sendIoTMessage function in the getItem 
 * call backto determine what temprature regulation systems need to be turned off/on
 * 
 * @param {double} currentTemp this is the current temprature reading from 
 * @return {null} returns null on completion
 * */

function getIdealTemp(currentTemp) {

    console.log('Getting Users Ideal Temp');

    let getParams = {
        TableName: 'tempData',
        Key: {
            'userID': {
                'S': 'testDevice'
            }
        }
    }

   let item = DynamoDB.getItem(getParams, function (err, data) {

        console.log('Accessing tempData Table');

        if (err) {
            console.log(err); 
        } else {
            console.log('Retrieved idealTemp from tempData Table');
            let idealTemp = data.Item.idealTemp.N;
            sendIoTMessage(idealTemp,currentTemp);
        }

    });
return;
}

/**
 * This function determines which system will need to be turned off/on
 * based on the users current ambient temprature and there preffered 
 * ambient temprature. Once the correct temprature regulation system
 * states are determined and IoT message is sent to those devices to 
 * be turned off/on;
 * 
 * @param {double} idealTemp this is the users ideal Ambient temprature
 * @param {double} currentTemp this is the users current Ambient temprature
 * @return {null}  return null on completion
 */
function sendIoTMessage(idealTemp,currentTemp) {

    if (currentTemp >= idealTemp) {

        topic = 'cooling';
        message = {
            message: 'turnOn'
        }

        iotdata.publish({topic,message,qos:0});
        console.log('Sent turnOn Message to Cooling Topic');

        topic = 'heating';
        message = {
            message: 'turnOff'
        }
        
        iotdata.publish({topic,message,qos:0});
        console.log('Sent turnOff Message to heating Topic');

    } else if (currentTemp <= idealTemp) {

        topic = 'cooling';
        message = {
            message: 'turnOff'
        }
        
        iotdata.publish({topic,message,qos:0});
        console.log('Sent turnOff Message to cooling Topic');

        topic = 'heating';
        message = {
            message: 'turnOn'
        }

        console.log('Sent turnOn Message to heating Topic');
        iotdata.publish({topic,message,qos:0});

    }

    return;
}
