import { Text, View, StyleSheet } from 'react-native';
import { processEngineState } from 'react-native-playstation-ui-bridge';

const result = processEngineState('chat');

export default function App() {
  return (
    <View style={styles.container}>
      <Text>Engine State: {result}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
});
