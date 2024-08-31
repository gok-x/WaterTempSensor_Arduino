#ifndef _SECRET_CERTS_HPP_
#define _SECRET_CERTS_HPP_
const char * const SECRET_CERTIFICATE = R"(-----BEGIN CERTIFICATE-----
-----END CERTIFICATE-----
)";
const char * const AWS_IOT_ENDPOINT = "your aws iot endpoint url e.g. a3qjEXAMPLEffp-ats.iot.us-west-2.amazonaws.com";
const int AWS_IOT_ENDPOINT_PORT = "your aws iot port number e.g. 443";
const char * const AWS_IOT_TOPIC = "your url_encoded_topic_name e.g. device%2Fmessage";
const char * const AWS_IOT_QOS = "your qos e.g. 1";
#endif