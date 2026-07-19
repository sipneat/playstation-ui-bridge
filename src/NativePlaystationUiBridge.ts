import { TurboModuleRegistry, type TurboModule } from 'react-native';

export interface Spec extends TurboModule {
  processEngineState(payload: string): string;
}

export default TurboModuleRegistry.getEnforcing<Spec>('PlaystationUiBridge');
